#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main() {
ll n;cin>>n;
ll sum=0;
    for (ll i=1;i<=n/i;i++) {
        if (n%i==0) {
            sum+=i;
            if (n/i !=i)sum+=n/i;
        }
    }
    cout<<sum<<ln;
}