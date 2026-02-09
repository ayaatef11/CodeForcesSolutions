#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int T, A;
int n;

int oxy[1005];
int nit[1005];
int w[1005];

int dp[1005][22][80];

int solve(int i, int o, int n2) {
    if (o <= 0 && n2 <= 0)
        return 0;
    if (i == n)
        return INF;
    o = max(0, o);
    n2 = max(0, n2);

    if (dp[i][o][n2] != -1)
        return dp[i][o][n2];

    int leave = solve(i + 1, o, n2);

    int take = w[i] + solve(i + 1,o - oxy[i], n2 - nit[i]);

    return dp[i][o][n2] = min(leave, take);
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        cin >> T >> A;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> oxy[i] >> nit[i] >> w[i];
        }

        memset(dp, -1, sizeof(dp));

        cout << solve(0, T, A) << endl;
    }
}
