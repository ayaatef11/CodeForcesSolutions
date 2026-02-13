#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main() {
fast();
    int n, m, k;
    ll ta, tb; cin>>n>>m>>ta>>tb>>k;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];
    if (k >= n || k >= m) {
        cout <<-1<<ln;
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        int canceledA = i;
        int canceledB = k - i;
        if (canceledA >= n) break;
        ll arrivalB = a[canceledA] + ta;
        int j = lower_bound(b.begin(), b.end(), arrivalB) - b.begin();
        if (j == m) {
            cout << -1 << "\n";
            return 0;
        }
        j += canceledB;
        if (j >= m) {
            cout << -1 <<ln;
            return 0;
        }
        ans = max(ans, b[j] + tb);
    }
    cout << ans <<ln;
    return 0;
}
