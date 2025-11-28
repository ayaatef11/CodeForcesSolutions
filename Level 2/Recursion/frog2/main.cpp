#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;
vector<int> dp;

int solve(int i) {
   if (i==n-1)return 0;  
   if (dp[i]!=-1)return dp[i];

   int ans=INT_MAX;
   for (int j=1;j<=k;j++) {
      if (i+j<n) {
         int cost=abs(v[i]-v[i+j])+solve(i+j);
         ans=min(ans,cost);
      }
   }

   dp[i]=ans;
   return dp[i];
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin>>n>>k;
   v.resize(n);
   dp.resize(n, -1);

   for (int i = 0; i < n; i++) cin >> v[i];

   cout << solve(0) << "\n";
}
