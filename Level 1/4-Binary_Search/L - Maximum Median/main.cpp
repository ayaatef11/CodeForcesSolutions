#include <bits/stdc++.h>
using namespace std;
#define ll long long
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}
#define  ln '\n'
int main() {
   fast();
    int n;
    ll k; cin>>n>>k;
    vector<ll> a(n);
    for (int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(), a.end());
    int mid = n/2;
    ll left = a[mid], right = 1e18, ans = a[mid];
    while (left <= right) {
        ll m = (left + right) / 2;
        __int128 need = 0;
        for (int i = mid; i < n; i++) {
            if (a[i] < m) need += (m - a[i]);
            if (need > k) break;
        }

        if (need <= k) {
            ans = m;
            left = m + 1;
        } else {
            right = m - 1;
        }
    }

    cout << ans <<ln;
}
