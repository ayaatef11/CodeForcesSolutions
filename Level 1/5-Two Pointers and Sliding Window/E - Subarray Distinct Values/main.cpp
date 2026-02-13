#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main() {
    fast();
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    unordered_map<int,int> freq;
    ll ans = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        freq[arr[r]]++;
        while ((int)freq.size() > k) {
            freq[arr[l]]--;
            if (freq[arr[l]] == 0) freq.erase(arr[l]);
            l++;
        }
        ans += (r - l + 1);
    }
    cout<<ans<<ln;
}
