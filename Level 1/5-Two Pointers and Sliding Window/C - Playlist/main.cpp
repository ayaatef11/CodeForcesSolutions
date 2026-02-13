#include <bits/stdc++.h>
using namespace std;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}
#define ln '\n'
int main() {
    fast();
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    map<int, int> freq;
    int i = 0, j = 0, mx = 0;

    while (j < n) {
        freq[arr[j]]++;
        while (freq[arr[j]] > 1) {
            freq[arr[i]]--;
            i++;
        }
        mx = max(mx, j - i + 1);
        j++;
    }

    cout << mx <<ln;
}
