#include <bits/stdc++.h>
using  namespace std;
#define ll long long
#define ln '\n'
const int MAXN=1e6+4;
const int MOD=1e9+7;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main() {
int n;cin>>n;
    vector<int> v(n+1,1);
    int f=n;
    while (n--) {
        int x=n+1;
        for(int i=2;i<=x;i++){
            while(x%i==0) {
                v[i]++;
                x/=i;
            }
        }
    }
    ll res=1;
    for(int i=2;i<=f;i++) {
        res=(res*v[i])%MOD;
    }
cout<<res<<ln;
}