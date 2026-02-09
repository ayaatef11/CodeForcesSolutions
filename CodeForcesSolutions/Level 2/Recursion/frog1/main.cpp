#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<int>dp;
vector<int>v;
int solve(int i) {
 if (i == n-1) {return 0;}
 if (dp[i]!=-1) return dp[i];
 int cost1 = INT_MAX, cost2 = INT_MAX;

 if (i+1 < n) cost1 = abs(v[i] - v[i+1]) + solve(i+1);
 if (i+2 < n) cost2 = abs(v[i] - v[i+2]) + solve(i+2);

 dp[i] = min(cost1, cost2);
 return dp[i];
}
int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
cin>>n;
 v.resize(n);
 dp.resize(n,-1);
 for(int i=0;i<n;i++)cin>>v[i];
cout<<solve(0);
}