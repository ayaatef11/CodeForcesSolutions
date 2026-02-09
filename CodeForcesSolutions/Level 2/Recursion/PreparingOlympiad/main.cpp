#include <bits/stdc++.h>
using namespace std;

int n;
long long l, r, x;
vector<long long> c;
long long ways = 0;

void dfs(int idx, int cnt, long long sum, long long mn, long long mx) {
    if (idx == n) {
        if (cnt >= 2 && sum >= l && sum <= r && (mx - mn) >= x) ways++;
        return;
    }
    dfs(idx + 1, cnt, sum, mn, mx);

    long long newSum = sum + c[idx];
    long long newMn = (cnt == 0) ? c[idx] : min(mn, c[idx]);
    long long newMx = (cnt == 0) ? c[idx] : max(mx, c[idx]);
    dfs(idx + 1, cnt + 1, newSum, newMn, newMx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l >> r >> x;
    c.resize(n);
    for (int i = 0; i < n; ++i) cin >> c[i];

    dfs(0, 0, 0LL, LLONG_MAX, LLONG_MIN);
    cout << ways << "\n";
    return 0;
}
