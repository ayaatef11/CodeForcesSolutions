#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define ll long long
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}
int main() {
    fast();
    int n,t; cin>>n>>t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, ans = 0;
    ll sum = 0;

    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum>t) {
            sum-=a[l],l++;
        }
        ans=max(ans, r-l+1);
    }

    cout<<ans<<ln;
    return 0;
}
