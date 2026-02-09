#include <bits/stdc++.h>
using namespace std;

string s, t;
int n, m;
int dp[205][205][205];
char openBracket = '(', closeBracket = ')';

int go(int i, int j, int sum) {
    if (sum < 0) return 1e9;
    if (i == n && j == m) return sum;

    if (dp[i][j][sum] != -1) return dp[i][j][sum];

    int res = 1e9;

    // Option 1: add '('
    int ni = i + (i < n && s[i] == '(');
    int nj = j + (j < m && t[j] == '(');
    res = min(res, go(ni, nj, sum + 1) + 1);

    // Option 2: add ')'
    if (sum > 0) { // can only add ')' if there's an unmatched '('
        ni = i + (i < n && s[i] == ')');
        nj = j + (j < m && t[j] == ')');
        res = min(res, go(ni, nj, sum - 1) + 1);
    }

    return dp[i][j][sum] = res;
}

// Reconstruct the answer
void build(int i, int j, int sum) {
    if (i == n && j == m) {
        while (sum--) cout << ')';
        return;
    }

    int ni = i + (i < n && s[i] == '(');
    int nj = j + (j < m && t[j] == '(');
    if (go(ni, nj, sum + 1) + 1 == go(i, j, sum)) {
        cout << '(';
        build(ni, nj, sum + 1);
        return;
    }

    if (sum > 0) {
        ni = i + (i < n && s[i] == ')');
        nj = j + (j < m && t[j] == ')');
        if (go(ni, nj, sum - 1) + 1 == go(i, j, sum)) {
            cout << ')';
            build(ni, nj, sum - 1);
        }
    }
}

int main() {
    cin >> s >> t;
    n = s.size();
    m = t.size();

    memset(dp, -1, sizeof(dp));
    go(0, 0, 0);
    build(0, 0, 0);
    cout << endl;
    return 0;
}
