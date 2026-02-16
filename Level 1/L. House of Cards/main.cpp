#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}
int main() {
string s;cin>>s;
    int n=s.size();
    vector<int> v(n+1,0);// /
vector<int> h(n+1,0);// \ /
    vector<int> c(n+1,0);// -
    for (int i=0;i<n;i++) {
        v[i+1]=v[i];
        h[i+1]=h[i];
        c[i+1]=c[i];
        if (s[i]=='/')v[i+1]++;
        else if (s[i]=='\\')h[i+1]++;
        else if (s[i]=='_')c[i+1]++;
    }
    int q;cin>>q;
    while (q--) {
        int l , r;cin>>l>>r;
        int cntSlash=v[r]-v[l-1];
        int cntBackSlash=h[r]-h[l-1];
        int cntUnderScore=c[r]-c[l-1];
        // int ans=min({cntSlash,cntBackSlash,cntUnderScore+1});
        ll rooms = min(cntSlash, cntBackSlash);
        ll ceilings = cntUnderScore;

        ll ans = 0;
        for (ll h =1; ; h++) {
            ll needRooms=h*(h+1)/2;
            ll needCeil=h*(h-1) /2;
            if (needRooms<=rooms&&needCeil<=ceilings)
                ans=h;
            else
                break;
        }
        cout<<ans<<ln;
    }

}