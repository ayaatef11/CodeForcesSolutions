#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main() {
int n;cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin>>v[i];
    int l=1;
    for (int i=1;i<=9;i++)
        l=lcm(l,i);
    vector<vector<int>>dp(n+1,vector<int>(l,0));
dp[n][0]=1;

    for (int i = n-1; i>=0 ; i--) {
        for (int j=l-1;j>=0;j--) {
            dp[i][j]=(dp[i+1][j]+dp[i+1][(v[i]*j)%l])%MOD;
        }
    }
cout<<dp[0][1];
}