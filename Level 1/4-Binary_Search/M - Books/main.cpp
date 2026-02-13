#include <bits/stdc++.h>
#define ln '\n'
#define ll long long
using namespace std;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}
int main() {
    fast();
    int n,t;
    cin>>n>>t;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];

    int l=0,r=0;
    ll sum = 0;
    int ans = 0;

    while (r < n) {
        sum += a[r];
        while (sum > t) {
            sum -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }

    cout<<ans<<ln;
    return 0;
}
