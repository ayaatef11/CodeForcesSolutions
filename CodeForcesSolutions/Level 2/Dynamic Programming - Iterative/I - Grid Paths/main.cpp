#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
int main() {
    int n;
    cin>>n;
    vector<vector<char>> v(n,vector<char>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>v[i][j];
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    dp[n][n]=1;
    for(int i=n;i>0;--i)
        for(int j=n;j>0;--j) {
            if (v[i-1][j-1]=='*')dp[i][j]=0;
            else{
                if (i<n) dp[i][j]=(dp[i][j]+dp[i+1][j])%MOD;
                if (j<n) dp[i][j]=(dp[i][j]+dp[i][j+1])%MOD;
            }
        }
    cout<<dp[1][1];
}