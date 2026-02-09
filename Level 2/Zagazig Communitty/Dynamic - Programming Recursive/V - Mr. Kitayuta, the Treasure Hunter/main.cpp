#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 30005;
const int SHIFT = 250;

int n, d, mx;
int dp[N][505];
vector<int> frq(N);

int go(int pos, int last) {
    if (pos > mx)
        return 0;

    if (last == 0)
        return 0;

    int &ret = dp[pos][last - d + SHIFT];
    if (ret != -1)
        return ret;

    int ans = 0;

    // jump length = last + 1
    ans = max(ans, go(pos + last + 1, last + 1) + frq[pos]);

    // jump length = last
    ans = max(ans, go(pos + last, last) + frq[pos]);

    // jump length = last - 1
    if (last > 1)
        ans = max(ans, go(pos + last - 1, last - 1) + frq[pos]);

    return ret = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;

    mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        frq[x]++;
        mx = max(mx, x);
    }

    memset(dp, -1, sizeof(dp));

    cout << go(d, d) << '\n';
    return 0;
}
