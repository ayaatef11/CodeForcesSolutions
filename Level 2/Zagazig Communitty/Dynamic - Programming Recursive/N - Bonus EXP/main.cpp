#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2e5;
ll dp[MAXN][2];
ll solve(vector<ll>&arr, int i,int j) {
if (i==arr.size()) return 0;
    int parity;
    if ((j+1)%2==0)parity=1;
    else parity=0;
    if (dp[i][parity] != -1) return dp[i][parity];
    ll take=solve(arr,i+1,j+1)+arr[i]*(parity?2:1);
    ll leave=solve(arr,i+1,j);
    return dp[i][parity]=max(take,leave);
}
int main() {
int n;cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
cout<<solve(arr,0,0)<<endl;
}