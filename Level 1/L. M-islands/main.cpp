//link https://codeforces.com/group/T3p02rhrmb/contest/343396/problem/L
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<pair<ll,ll>> randes;
vector<pair<ll,ll>> merged;

bool can(ll u, ll v ) {
    // int l=0,r=(int)merged.size()-1;
    // while(l<r) {
    //     ll m = l+(r-l)/2;
    //     if(u>=merged[m].first && v<=merged[m].second) return true;
    //     else if (u>=merged[m].first)l = m+1;
    //     else r = m-1;
    // }
    // return false;
    for (int i =0; i <(int )merged.size(); i++) { if (u>=merged[i].first && v<=merged[i].second) return true; } return false;
}

int main() {
    fast();
ll n,m;cin>>n>>m;
    randes.resize(n);
    for (int i=0;i<n;i++) {//o(n)
        ll x,y;cin>>x>>y;
        if (x>y) {
            ll c=x;
            x=y;
            y=c;
        }
        randes[i].first=x,randes[i].second=y;
    }

    sort(randes.begin(),randes.end());//o(n log n)

    for (int i=0;i<n;i++) {
        // compine connected segments
        ll l=randes[i].first;
        if (merged.empty() || merged.back().second<l-1)
            merged.emplace_back(randes[i]);
        else
            merged.back().second=max(merged.back().second, randes[i].second);
    }

    int q;cin>>q;
    while (q--) {//o(log n * q)
        ll u,v;cin>>u>>v;
        if (u>v)swap(u,v);

       if (can(u,v)) cout<<"YES";
        else cout<<"NO";
        cout<<ln;
    }

}