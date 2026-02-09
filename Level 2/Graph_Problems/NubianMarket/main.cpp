#include <bits/stdc++.h>
using namespace std;

long long n, S;
vector<long long> a;
pair<int, long long> canBuy(int k) {
    vector<long long> costs(n);
    for (int i = 0; i < n; i++) {
        costs[i] = a[i] + (long long)(i + 1) * k;
    }
    sort(costs.begin(), costs.end());
    long long sum = 0;
    for (int i = 0; i < k; i++) sum += costs[i];
    if (sum <= S) return {k, sum};
    return {0, 0};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> S;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int low = 0, high = n;
    int bestK = 0;
    long long bestCost = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        auto [k, cost] = canBuy(mid);
        if (k > 0) {
            bestK = k;
            bestCost = cost;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << bestK << " " << bestCost << "\n";
    return 0;
}
