//link : https://codeforces.com/group/T3p02rhrmb/contest/343965/problem/L
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int MAXN = 1e9+1;
#define vii(v,n) for(int i=0;i<n;i++)cin>>v[i]
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
void solve() {
    int n;cin>>n;
    vector<int> v(n);
  vii(v,n);
    int l=0,r=n-1;
    ll sumA=0,sumB=0;
ll last=0;
    int moves=0;
    bool alice=true;
    while (l<=r) {
        ll current=0;
        if (alice) {
            while (l<=r && current<=last) {
                current+=v[l++];
            }
            sumA+=current;
        }else {
            while (l<=r && current<=last) {
                current+=v[r--];
            }
            sumB+=current;
        }

        last=current;
        moves++;
        alice=!alice;
    }
    cout<<moves<<" "<<sumA<<" "<<sumB<<ln;
}
int main() {
int t;cin>>t;
    while (t--) {
        solve();


    }

}