#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, k;
int a[105], b[105];
int dp[105][20005];
int OFFSET = 10000;

int solve(int i, int sumC) {
    if (i == n) {
        if (sumC == 0) return 0;
        return -INF;
    }

    int &res = dp[i][sumC + OFFSET];
    if (res != -1) return res;

    int leave = solve(i + 1, sumC);

    int ci = a[i] - k * b[i];
    int take = solve(i + 1, sumC + ci) + a[i];

    return res = max(leave, take);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    memset(dp, -1, sizeof(dp));

    int ans = solve(0, 0);

    if (ans <= 0) cout << -1 << endl;
    else cout << ans << endl;
}
