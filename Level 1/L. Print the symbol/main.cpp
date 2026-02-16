#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
ll solve(ll n,ll k) {
    if (n==1)return 0;
    ll half=1LL<<(n-2);

    if (k<=half)
        return solve(n-1,k);
    else
        return 1-solve(n-1,k-half);
}
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main() {
    fast();
    int t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        cout<<solve(n,k)<<ln;
    }

    return 0;
}
