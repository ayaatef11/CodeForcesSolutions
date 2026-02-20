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
    ll n;
    while (true){
        cin>>n;
        if (n==0)break;
        vector<pair<ll,int>> v;
        for(int i=2;i<=n/i;i++) {
            int cnt=0;
            while(n%i==0) {
                cnt++;
                n/=i;
            }
            if(cnt>0)v.emplace_back(i,cnt);
        }
        if (n>1)v.emplace_back(n,1);
        for(int i=0;i<v.size();i++) {
          cout<<v[i].first<<"^"<<v[i].second<<" ";
        }
        cout<<ln;
    }
}