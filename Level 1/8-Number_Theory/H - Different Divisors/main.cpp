#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void optmize() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}
const int MAXN = 30000;
vector<bool> isPrime;
//optmized sieve
void sieve() {
    isPrime[0]=isPrime[1]=false;
    for (int i=2;i<=MAXN/i;i++) {
        if (isPrime[i]) {
            for (int j=i*i;j<=MAXN;j+=i)
                isPrime[j]=false;
        }
    }
}

int main() {
    optmize();
    isPrime.assign(MAXN+1,true);
sieve();
    int t;cin>>t;
    while(t--) {
        int d;cin>>d;
        int p=0,q=0;
        for (int i=d+1;i<=MAXN;i++) {
            if (isPrime[i]) {
                p=i;
                break;
            }
        }

        for (int i=p+d;i<=MAXN;i++) {
            if (isPrime[i]) {
                q=i;
                break;
            }
        }

        cout <<1LL*p*q<<ln;//use 1ll to not cause overflow
    }

}