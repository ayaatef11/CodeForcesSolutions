#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<ll> evens, odds;
        for (ll v : a) {
            if (v % 2 == 0) evens.push_back(v);
            else odds.push_back(v);
        }

        if (evens.size() >= 2) {
            cout << evens[0] << " " << evens[1] << "\n";
            continue;
        }

        ll x = odds[0];
        bool found = false;

        for (int i = 1; i < odds.size(); ++i) {
            ll y = odds[i];
            if ((y % x) % 2 == 0) {
                cout << x << " " << y << "\n";
                found = true;
                break;
            }
        }

        if (!found) cout << -1 << "\n";
    }
    return 0;
}
