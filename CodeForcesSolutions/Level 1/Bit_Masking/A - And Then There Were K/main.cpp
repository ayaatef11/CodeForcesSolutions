#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;cin>>t;
    while (t--) {
        int n;cin>>n;
        int bits = 32 - __builtin_clz(n);
        bits--;
        int k=(1<<bits);

        cout<<k-1<<'\n';
    }
}