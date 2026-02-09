#include <bits/stdc++.h>
using namespace std;
const int MAXN=101;
int dp[MAXN];
int solve(vector<int>&v,int i) {
    if (i < 0)return 0;
    if (dp[i]!=-1) return dp[i];
    return dp[i]=v[i] + solve(v,i - 1);
}
int main() {
int t;cin>>t;
    int x=t;
    while (t--) {
        int n;cin>>n;
        vector<int> v(n);
        for (int i=0;i<n;i++)cin>>v[i];
        memset(dp,-1,sizeof(dp));
        int ans =solve(v,n-1);
        cout<<"Case "<<x-t<<": "<<ans<<"\n";
    }
}