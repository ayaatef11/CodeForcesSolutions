#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,l,r,x;
    cin >>n>>l>>r>> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum=0,mn=INT_MAX, mx = INT_MIN, cnt = 0;
        for (int i=0;i<n;i++) {
            if (mask&(1<<i)) {
                cnt++;
                sum += a[i];
                mn=min(mn,a[i]);
                mx=max(mx,a[i]);
            }
        }
        if (cnt>= 2&&sum>=l&&sum<= r&&(mx-mn)>=x)  ans++;
    }

    cout << ans << "\n";
    return 0;
}
