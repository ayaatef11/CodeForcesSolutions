//link https://codeforces.com/group/T3p02rhrmb/contest/343396/problem/Q
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int MAXN=1e9;
void fast() {
  ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
ll h,n,k;
bool can(ll num,ll maxRes) {
    if (num<=maxRes/(num+1) ) return true;
    return false;
}
int main() {
    fast();
cin>>h>>n>>k;
    ll maxRes=1LL*(h*40)-2*k/3;
ll l=1,r =n;
    ll ans=0;
    while (l<=r) {
        ll m=l+(r-l)/2;
        if (can(m,maxRes)) {
            l=m+1;
            ans=m;
        }
        else r=m-1;
    }
    cout<<ans<<ln;
}