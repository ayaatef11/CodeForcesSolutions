#include <bits/stdc++.h>
#define ll long long
#define ln '\n'

using namespace std;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}
int main() {
fast();
    int n,k;
    cin>>n>>k;
    vector<ll>a(n);
    ll sum=0,mx=0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }

    ll left=mx,right = sum, ans = sum;

    while (left<=right) {
        ll mid =(left+right)/2;
        ll cur = 0;
        int parts = 1;
        for (int i = 0; i < n; i++) {
            if (cur+a[i]>mid) {
                parts++,cur=0;
            }
            cur+=a[i];
        }

        if (parts<=k) {
            ans=mid;
            right=mid-1;
        } else {
            left=mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
