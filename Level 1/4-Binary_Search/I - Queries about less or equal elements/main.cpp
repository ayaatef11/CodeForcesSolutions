#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n,m;cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++) {
        cout<<upper_bound(a.begin(),a.end(),b[i])-a.begin()<<" ";

    }
}