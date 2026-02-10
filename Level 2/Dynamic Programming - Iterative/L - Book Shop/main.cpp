#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
int n,x;cin>>n>>x;
    vector<int>prices(n);
    vector<int>pages(n);
    for (int i=0;i<n;i++)cin>>prices[i];
    for (int i=0;i<n;i++)cin>>pages[i];
    vector<int>dp(x+1,0);
    for (int i=0;i<n;i++) {
        for (int j=x;j>=prices[i];j--) {
            dp[j]=max(dp[j],dp[j-prices[i]]+pages[i]);
        }
    }
    cout<<dp[x];
}