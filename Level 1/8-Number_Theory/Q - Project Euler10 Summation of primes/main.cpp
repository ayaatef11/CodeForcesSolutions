#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int MAXN = 1e6 + 5;
bitset<MAXN> is_prime;
ll sumPrimes[MAXN];
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}
void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i * i < MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    sumPrimes[0]=0;
    for (int i=1;i<MAXN;i++) {
        sumPrimes[i]=sumPrimes[i-1];
        if (is_prime[i])sumPrimes[i]+=i;
    }
}

int main() {
 fast();
    sieve();
    int t;
    cin>>t;
    while(t--) {
        int n;cin>>n;
        cout <<sumPrimes[n]<<ln;
    }
}
