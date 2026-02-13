#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll  totalLines(ll v, int k) {
    ll sum = 0;
    ll cur = v;
    while (cur > 0) {
        sum += cur;
        cur /= k;
    }
    return sum;
}
int main() {
   fast();
    ll n;
    int k;
    cin >> n >> k;
    ll low = 1, high = n, ans = n;
    while (low <= high) {
        ll mid = (low + high) / 2;

        if (totalLines(mid, k) >= n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans <<ln;
    return 0;
}
