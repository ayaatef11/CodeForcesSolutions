#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,w;
vector<int> values;
vector<int> weights;
const int MAX = 1e3+1;
int dp[MAX][101];
int solve(int v,int i) {
    if (i==values.size())return 0;
    if (dp[v][i]!=-1)return dp[v][i];
    int take=solve(v+values[i],i+1)+(weights[i]/values[i]);
    int leave=solve(v,i+1);
    return dp[v][i]= max(take,leave);
}
int main() {
cin>>n>>w;
    values.resize(n);
    weights.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) {
        cin>>weights[i]>>values[i];
    }
cout<<solve(0,0)<<endl;
}