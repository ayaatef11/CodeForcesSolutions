#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

set<ll>ss;
ll getFirstDivisor(ll x) {//it causes time limit

    for (ll i=x; ;i+=x) {//to maximize it unitl find the right value
        if (!ss.count(i))return i;
    }
}
int main() {
int t;cin>>t;
    ss.insert(0);
    while (t--) {
       char c;
        ll x;cin>>c>>x;
        if (c=='+')ss.insert(x);
        else if (c=='?')cout<<getFirstDivisor(x)<<ln;
    }

}