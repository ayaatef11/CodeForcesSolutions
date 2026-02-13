#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int MAXN = 1e5 + 5;
bitset<MAXN> is_prime;
vector<int>primes;

void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int i=2;i<MAXN/i; i++) {
        if (is_prime[i]) {
            for (int j=i*i; j<MAXN;j+=i) {
                is_prime[j] = 0;
            }
        }
    }

    for (int i=2;i<MAXN;i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    sieve();
int t;cin>>t;
    while(t--) {
        int n;cin>>n;
        cout<<primes[n-1]<<ln;
    }

}