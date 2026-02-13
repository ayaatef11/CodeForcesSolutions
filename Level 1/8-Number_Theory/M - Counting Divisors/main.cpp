#include<bits/stdc++.h>
#define ll long long
#define ln '\n'
const int MAXN = 1e6 + 5;
using namespace std;
void fastIO() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> divisors(MAXN,1);
void calcDivisors() {//sieve divisor is important
    for (int i = 2; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j+=i) {
                divisors[j]++;
        }
    }
}
int main() {
    fastIO();
    calcDivisors();
int t;cin>>t;
    while(t--) {
        int n;cin>>n;
        cout<<divisors[n]<<ln;
    }

}