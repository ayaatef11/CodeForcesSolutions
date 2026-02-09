#include <bits/stdc++.h>
using namespace std;

int solve(string &s, int l, int r, char c) {
    if (l == r)
        return (s[l] == c ? 0 : 1);

    int mid = (l + r) / 2;

    int leftNotC = 0, rightNotC = 0;
    for (int i = l; i <= mid; i++)
        if (s[i] != c) leftNotC++;
    for (int i = mid + 1; i <= r; i++)
        if (s[i] != c) rightNotC++;

    int op1 = leftNotC + solve(s, mid + 1, r, c + 1);
    int op2 = rightNotC + solve(s, l, mid, c + 1);
    return min(op1, op2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s, 0, n - 1, 'a') << "\n";
    }
}
