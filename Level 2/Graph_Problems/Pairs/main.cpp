#include <bits/stdc++.h>
using namespace std;

bool checkCandidate(int x, const vector<pair<int,int>> &pairs) {
    vector<int> possibleY;
    for (auto &p : pairs) {
        if (p.first != x && p.second != x) {
            possibleY.push_back(p.first);
            possibleY.push_back(p.second);
            break;
        }
    }

    if (possibleY.empty()) return true;
    for (int y : possibleY) {
        bool ok = true;
        for (auto &p : pairs) {
            if (p.first != x && p.second != x &&
                p.first != y && p.second != y) {
                ok = false;
                break;
                }
        }
        if (ok) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> pairs(m);
    for (int i = 0; i < m; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    int a1 = pairs[0].first;
    int b1 = pairs[0].second;

    if (checkCandidate(a1, pairs) || checkCandidate(b1, pairs)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
