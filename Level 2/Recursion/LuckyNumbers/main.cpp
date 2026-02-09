#include <bits/stdc++.h>
using namespace std;

string n;
string ans = "99999999999";

void solve(string num, int fours, int sevens) {
    if (num.size() > n.size() + 1) return;

    if (fours == sevens && !num.empty()) {
        if (num.size() > n.size() || (num.size() == n.size() && num >= n)) {
            if (num < ans) ans = num;
        }
    }
    solve(num + '4', fours + 1, sevens);
    solve(num + '7', fours, sevens + 1);
}

int main() {
    cin >> n;
    solve("", 0, 0);
    cout << ans << endl;
    return 0;
}
