#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), prefix(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prefix[i] = a[i] + (i > 0 ? prefix[i - 1] : 0);
    }
    for (int j = 0; j < m; j++) {
        long long b;
        cin >> b;
        int l = 0, r = n - 1, dorm = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (prefix[mid] >= b) {
                dorm = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        long long room = b - (dorm > 0 ? prefix[dorm - 1] : 0);
        cout << dorm + 1 << " " << room << "\n";
    }

    return 0;
}
