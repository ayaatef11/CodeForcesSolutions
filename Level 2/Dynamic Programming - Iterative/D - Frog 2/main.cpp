#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 998244353;

int main() {
    int n,k;cin>>n>>k;
    vector<int>h(n+1);
    for(int i=1;i<n+1;i++)cin>>h[i];
    vector<int>dp(n+1,1e9);
    dp[1]=0;
    if (n>=2)dp[2]=abs(h[2]-h[1]);

    for (int i=3;i<=n;i++) {
        for (int j=1;j<=k;j++) {
            if (i - j >= 1) dp[i]=min(dp[i-j]+abs(h[i]-h[i-j]),dp[i]);
else break;
        }
    }
    cout<<dp[n];
}