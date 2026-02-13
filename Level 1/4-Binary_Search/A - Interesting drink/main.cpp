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
    int n;cin>>n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());
    int q;cin>>q;
    while (q--) {
        ll m;cin>>m;

        int l=0, r=n-1, ans=-1;
        while (l<=r) {
            int mid = l+(r-l)/2;
            if (prices[mid] <= m) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout<<(ans+1)<<ln;
    }

    return 0;
}
