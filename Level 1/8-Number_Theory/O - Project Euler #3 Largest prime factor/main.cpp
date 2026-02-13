#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define ll long long
ll getGreatestPrimeDivisor(const ll x) {
    ll ans=-1;
    ll c=x;
    for (ll i = 2; i<=x/i;i++) {
        while (!(c%i) ) {
            ans = i;
            c/=i;
        }
    }
    if (c>1) ans = c;
    return ans;
}
int main() {
int t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        ll ans=getGreatestPrimeDivisor(n);
        cout<<ans<<ln;
    }
}