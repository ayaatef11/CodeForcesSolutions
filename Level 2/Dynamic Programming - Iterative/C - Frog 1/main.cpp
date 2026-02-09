#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 998244353;

int main() {
int n;cin>>n;
    vector<int>h(n+1);
    for(int i=1;i<n+1;i++)cin>>h[i];
    vector<int>dp(n+1,1e9);
    dp[1]=0;
    if (n>=2)dp[2]=abs(h[2]-h[1]);

    for (int i=3;i<=n;i++) {
        dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout<<dp[n];
}