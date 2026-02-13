//link : https://codeforces.com/group/T3p02rhrmb/contest/343396/problem/W
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
fast();
    ll n,k;cin>>n>>k;
    ll t=n-1;
    ll maxSum=k*(k-1)/2;
    if (t>maxSum) {
        cout<<-1<<ln;
        return 0;
    }
    ll l=1,r=k-1,ans=k-1;
    while (l<=r) {
        ll m=l+(r-l)/2;
        ll sum=m *(k-m-1)/2;
        if (sum>=t) {
            ans=m;
            r=m-1;
        }else l=m+1;
    }

cout<<ans<<ln;
}