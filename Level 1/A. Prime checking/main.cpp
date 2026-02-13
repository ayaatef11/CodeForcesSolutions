#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
int main() {
ll n;cin>>n;
    if (n==1 ) {
        cout<<"NO";
        return 0;
    }
    for (ll i=2;i<=n/i;i++) {
        if (n%i==0) {
            cout<<"NO";
            return 0;
        }
    }
cout<<"YES";
}