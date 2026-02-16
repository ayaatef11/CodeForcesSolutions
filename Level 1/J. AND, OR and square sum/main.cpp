#include <bits/stdc++.h>
using namespace std;
#define ll long long

void singleTestCase() {
    ll n;cin>>n;
    vector<ll>bit_count(21,0);
    for (int i=0;i<n;++i) {
        ll x;cin>>x;
        for (int j=0;j<=20;++j) {//loop over bits of the number and count ones
            bit_count[j]+=(x>>j)&1;
        }
    }

    ll ans=0;

    while(n--) {
        ll sum=0;
        for (int i=0;i<=20;++i) {//make a number that have at most 1s bit
            if (bit_count[i]) {
                sum|=(1LL<<i);
                bit_count[i]--;
            }
        }
        ans+=(sum*sum);
    }

    cout<<ans<<'\n';
}
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main() {
    fast();
    singleTestCase();
    return 0;
}
