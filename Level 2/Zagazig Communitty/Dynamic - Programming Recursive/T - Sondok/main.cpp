#include <bits/stdc++.h>
using namespace  std;
#define ll long long
const int MOD=1e9+7;
vector<vector<ll>> dp;
ll solve(int i, int j,int n,int m) {
   if (i >= n || j >= m) return 0;
   if (i == n-1 && j == m-1) return 1;
   if (dp[i][j]!=-1)return dp[i][j];
   int right=solve(i,j+1,n,m);
   int down=solve(i+1,j,n,m);
   return dp[i][j]=(right+down)%MOD;
}
int main() {
int n;cin>>n;
   while (n--) {
      int n,m;cin>>n>>m;
      dp.assign(n,vector<ll>(m,-1));
      cout<<solve(0,0,n,m)<<"\n";
   }

}