//link : https://codeforces.com/group/3nQaj5GMG5/contest/377898/problem/B
#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll a,b;
    cin>>a>>b;
    int cnt=0;

    for (int i=2;i<=60;i++) {
        ll ans=(1LL<<i)-1;//dont skip LL as it may cause overflow
        for (int j=0;j<i-1;j++) {
            ll num= ans^(1LL<<(j));
            if (num>=a&&num<=b)cnt++;
        }
    }

    cout<<cnt;
    return 0;
}
