#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int MAXN=3001;
vector<int>primes(MAXN,0);

void getPrimes(int x) {
    int c=x;
    for (int i = 2; i <=x/i; i++) {
        if (x % i == 0) primes[c]++;
        while (x % i == 0) {
            x/=i;
        }
    }
    if (x > 1) primes[c]++;
}
int main() {
int n;cin>>n;
    for(int i=2;i<=n;i++) {
        getPrimes(i);
    }
    int res=0;
    for (int i=1; i<primes.size(); i++) {
      if (primes[i]==2)  res++;
    }
    cout<<res;
}