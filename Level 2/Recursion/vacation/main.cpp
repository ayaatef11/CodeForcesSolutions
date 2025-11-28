#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> v;
vector<vector<int>> dp;
int solve(int i, int last) {
    if (i == n) return 0;
    if (dp[i][last] != -1) return dp[i][last];
    int ans = 0;
    for (int act = 0; act < 3; act++) {
        if (act != last) {
            ans = max(ans, v[i][act] + solve(i+1, act));
        }
    }
    return dp[i][last] = ans;
}

int main() {
    cin >> n;
    v.resize(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> v[i][j];
    dp.assign(n, vector<int>(3, -1));
    int result = solve(0, -1);
    cout << result;
}
