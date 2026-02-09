#include <bits/stdc++.h>
using namespace  std;
const int MOD=1000000007,INF=2e18,N=102,MAXN=1000;
int dp[N][MAXN];
int knapsack(int w,int i,int m,int k,pair<int,int>*arr) {
if (w>k)return -INF;
    if (i==m)return 0;
    if (dp[i][w]!=-1)return dp[i][w];
    int take=knapsack(w+arr[i].first,i+1,m,k,arr)+arr[i].second;
    int leave=knapsack(w,i+1,m,k,arr);
    return dp[i][w]=max(take,leave);
}
int main() {
int n;cin>>n;
    while (n--) {
        int k,m;cin>>k>>m;//max weight and number of bages
        pair<int,int> arr[m];
        memset(dp,-1,sizeof(dp));
        for (int i=0;i<m;i++) {
            int a,b;cin>>a>>b;//weight and value
            arr[i].first=a;
            arr[i].second=b;
        }
        cout<<"Hey stupid robber, you can get "<<knapsack(0,0,m,k,arr)<<"."<<endl;
    }
}