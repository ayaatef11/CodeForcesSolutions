#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >>n>>m)) return 0;
    vector<ll>a(n),b(m);
    for (int i=0;i<n;++i)cin>>a[i];
    for (int j=0;j<m;++j)cin>>b[j];
    ll D = 0;
    for (int i=1;i<n;++i) {
        ll diff=llabs(a[i]-a[0]);
        D=std::gcd(D,diff);
    }
    for (int j=0;j<m;++j) {
        ll val=a[0]+b[j];
        ll ans=std::gcd(val,D);
        cout<<ans<<(j+1<m?' ':'\n');
    }
    return 0;
}
