#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll>triangular;
void generateTriangularNumbers(ll maxi) {
    for (ll n=1;;n++) {
        ll t = n * (n + 1) / 2;
        if (t>maxi)break;
        triangular.push_back(t);
    }
}
int main() {
    int t;cin>>t;
    vector<pair<ll,ll>>queries(t);
    ll maxR=0;

    for (int i=0;i<t;i++) {
        cin>>queries[i].first>>queries[i].second;
        maxR=max(maxR,queries[i].second);
    }
generateTriangularNumbers(maxR);


    for (auto q : queries) {
        ll L = q.first;
        ll R = q.second;
        ll count = 0;
        for (size_t i = 0; i < triangular.size(); i++) {
            ll A = triangular[i];
            auto low = lower_bound(triangular.begin() + i, triangular.end(), L - A);
            auto high = upper_bound(triangular.begin() + i, triangular.end(), R - A);
            count += (high - low);
        }
        cout<<count<<ln;
    }

    return 0;
}
