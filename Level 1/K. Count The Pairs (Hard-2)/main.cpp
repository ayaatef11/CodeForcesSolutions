 //link: https://codeforces.com/group/T3p02rhrmb/contest/343965/problem/K
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
int main(){
   fast();
    int n;cin>>n;
    vector<ll>v(n);
map<ll,ll>m;
    ll biggest=0,smallest=MAXN;
    for(ll i=0;i<n;i++) {
        cin>>v[i];
        m[v[i]]++;
        biggest=max(biggest,v[i]);
        smallest=min(smallest,v[i]);
    }
    ll ans=0;

    if (biggest==smallest) {
        ans=1LL*n*(n-1)/2;//dont make 2 in the front as it chnag ethe value
        cout<<ans<<ln;
        return 0;
    }
    ll sum=biggest+smallest;
    sort(v.begin(),v.end());
    //1 2 4 5 6 6 8 8
    ll i=0,j=n-1;
    while(i<j) {
        ll sumation=(ll)v[i]+(ll)v[j];
        ll freqi=m[v[i]];
        ll freqj=m[v[j]];
        if (sumation==sum) {

            ans+=1LL*(freqi*freqj);
            i+=freqi;
            j-=freqj;
        }

        else if (sumation>sum) {
            j-=freqj;
        }
        else {
            i+=freqi;
        }
    }
    cout<<ans<<ln;
}