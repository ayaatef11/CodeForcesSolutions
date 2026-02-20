#include <bits/stdc++.h>
using  namespace std;
#define ll long long
#define ln '\n'
const int MAXN=1e6+4;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
fast();
    int n,m;cin>>n>>m;
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
ll gccc=0;
    for (int i=0;i<n;i++) {
        gccc=gcd(gccc,a[i]-a[0]);
    }
    for (int i=0;i<m;i++) {
        ll res=gcd(gccc,b[i]+a[0]);
        cout<<res<<" ";
    }
    cout<<ln;
}