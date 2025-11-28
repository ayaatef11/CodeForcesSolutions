#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int,int>>v;
int n,m;
int total=0;
int maxi=0;
int weight=0;
void solve(int i) {
if (i==n) {
    if (weight<=m)  maxi=max(maxi,total);
    return;
}
    if (weight>m) return;
    total+=v[i].second;
    weight+=v[i].first;
    solve(i+1);
    weight-=v[i].first;
    total-=v[i].second;
    solve(i+1);
}
int main() {
    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++) {
        cin>>v[i].first>>v[i].second;
    }
    solve(0);
    cout<<maxi;
}