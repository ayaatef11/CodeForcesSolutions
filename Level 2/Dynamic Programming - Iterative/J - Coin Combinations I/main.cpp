#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main() {
int n,x;cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int>dp(x+1,0);
    dp[0]=1;
for (int i=1;i<=x;i++) {
    for (int j = 0; j < n; j++) {
        int c = arr[j];
        if (i>=c)  dp[i]=(dp[i]+dp[i-c])%MOD;
    }
}
    cout<<dp[x];
}