#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int MAXN=1e6+1;//as x is 10^12 and we will take the sqrt
vector<int>primes;
void sieve() {
    primes[0]=primes[1]=0;
    for (int i=2;i<MAXN/i;i++) {
    for (int j=i*i; j<MAXN; j+=i) {
        primes[j]=0;
    }
    }
}
int main() {
    primes.assign(MAXN,1);
    sieve();
int t;cin>>t;
    while(t--) {
        ll n;cin>>n;
ll x=sqrt(n);
        if (1LL *x*x==n && primes[x])cout<<"YES\n";
        else cout<<"NO\n";
    }
}