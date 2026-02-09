#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main() {
    int n;cin>>n;
    int total=(n*(n+1))/2;
    if (total&1) {
        cout<<0<<endl;
        return 0;
    }
    int value=total/2;
    int dp[2][value+1];//we need for each value to calculate the total sets until we reach the target value
memset(dp,0,sizeof(dp));
    dp[0 &1][0]=1;
    for (int i=1;i<n;i++) {
        for (int j=0;j<=value;j++) {
            dp[i &1 ][j]=dp[(i-1)&1][j];
            if (j>=i) {
                dp[i & 1][j]=(dp[i &1][j]+dp[(i-1)&1][j-i])%MOD;
            }
        }
    }
cout<<dp[(n-1)&1][value]<<endl;


}