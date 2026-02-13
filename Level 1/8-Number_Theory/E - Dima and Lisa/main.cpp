#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
bool isPrime(int n) {
    if (n<2) return false;
    for (int i=2;i<=n/i;i++)
        if (n%i==0) return false;
    return true;
}

int main() {
    int n;
    cin>>n;
    if (isPrime(n)) {
        cout<<1<<ln;
        cout<<n<<ln;
        return 0;
    }
    if (isPrime(n-2)) {
        cout<<2<<ln;
        cout<<2<<" "<<(n-2)<<ln;
        return 0;
    }
    int first=3;
    int remaining=n-first;

    for (int i=2; i<=remaining;i++) {
        if (isPrime(i)&&isPrime(remaining-i)) {
            cout<<3<<ln;
            cout<<first <<" "<<i<<" "<<(remaining-i)<< '\n';
            return 0;
        }
    }

    return 0;
}
