//link :https://codeforces.com/group/T3p02rhrmb/contest/343965/problem/G
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
int n,d;cin>>n>>d;
    vector<ll> v(n);
    ll cnt=0;
    for (int i=0;i<n;i++)cin>>v[i];
    for (int i=0;i<n;i++) {
        int k;
            for (k=i+2;k<n;k++) {
                if (v[k]-v[i]>d)  break;
            }
        int len=k-i-1;
        if (len>=2)cnt+=(1LL*len*(len-1)/2);
        }

cout<<cnt;
}