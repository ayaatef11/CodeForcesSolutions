#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> cubes(n);
    for (int i = 0; i < n; i++) cin >> cubes[i];

    multiset<long long> tops;

    for (int i = 0; i < n; i++) {
        long long cube = cubes[i];
        auto it = tops.upper_bound(cube);
        if (it != tops.end()) {
            tops.erase(it);
        }
        tops.insert(cube);
    }
    cout << tops.size() << "\n";

    return 0;
}
