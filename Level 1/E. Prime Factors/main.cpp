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
    vector<pair<ll,ll>>v;
    for (ll i=2;i<=n/i;i++) {
        int cnt=0;
        while (n%i==0) {
            cnt++;
            n/=i;
        }
        if (cnt)v.emplace_back(i,cnt);
    }
    if (n>1)v.emplace_back(n,1);
for (auto p : v) {
    cout<<p.first<<" "<<p.second<<endl;
}
}