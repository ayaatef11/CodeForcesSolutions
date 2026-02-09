#include <bits/stdc++.h>
using namespace std;
int t,a,b;
int dp[5000005][2];
int solve(int c,int drink) {
    if (c>t)return INT_MIN;
    if (c==t)return c;
    if (dp[c][drink]!=-1)return dp[c][drink];
    return dp[c][drink]=max(c, max(solve(c+a,drink),max(solve(c+b,drink),(c>=2 &&drink==0)?solve(c/2,1):INT_MIN)));
}
int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

cin>>t>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0)<<endl;

}