#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
long long ans = 0;

void solve(int index, int evenCount, int oddCount, bool takenAny) {
    if (index == n) {
        if (takenAny && evenCount > oddCount) ans++;
        return;
    }

    if (arr[index] % 2 == 0)
        solve(index + 1, evenCount + 1, oddCount, true); // العنصر زوجي
    else
        solve(index + 1, evenCount, oddCount + 1, true); // العنصر فردي

    solve(index + 1, evenCount, oddCount, takenAny);
}

int main() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    solve(0, 0, 0, false);

    cout << ans;
}
