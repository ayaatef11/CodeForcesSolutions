#include <bits/stdc++.h>
using namespace std;
#define ll long long
set<ll>ss;
ll getKthDivisor(ll x, ll k) {
    for (int i=1;i<=x/i;i++) {
        if (x%i==0) {
            ss.insert(i);
            ss.insert(x/i);
        }
    }
    if (k>ss.size())return -1;
    vector<ll>divisor(ss.begin(),ss.end());//o(n)
    return divisor[k-1];
}
int main() {
ll n,k;cin>>n>>k;
    cout<<getKthDivisor(n,k)<<endl;

}