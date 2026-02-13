#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

int main() {
ll l ,r,m;cin>>l>>r>>m;
    ll ans=1;
    for (ll i=l;i<=r;i++) {
        ans*=i%m;
        ans%=m;
    }
cout<<ans;
}