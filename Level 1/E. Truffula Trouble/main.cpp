//link: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
    bool canCutTrees(vector<ll>&t,ll d,ll k) {
        ll count=0;
        for (ll i=0; i< t.size();i++) {
            if (d>=t[i]) {
                count++;
                i++;
                d--;
            }
            if (count>=k) return true;
        }
        return false;
    }

    int main() {
    fast();

    ll n, k;  cin >>n>>k;
    vector<ll> t(n);
    ll maxi=0;
    for (ll i=0;i<n;i++) {
        cin >> t[i];
        maxi = max(maxi,t[i]);
    }
    if (k>(n+1)/2) {
        cout<<-1;
        return 0;
    }
    ll l = 0,r=maxi+k,res = -1;

    while (l<=r) {
        ll mid = l +(r-l)/2;
        if (canCutTrees(t,mid,k)) {
            res=mid;
            r =mid-1;
        } else {
            l = mid+1;
        }
    }

    cout<<res<< ln;
}