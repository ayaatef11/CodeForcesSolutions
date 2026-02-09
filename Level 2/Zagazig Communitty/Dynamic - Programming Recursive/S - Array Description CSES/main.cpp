#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,m;
vector<int> a;
int solve(int i,int x) {
    if (i==a.size())return x;
    if (a[i]==0) {
        solve(i+1,x);
        solve(i+1,x+1);
    }
    solve(i+1,x);
}
int main() {
    cin>>n>>m;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
}