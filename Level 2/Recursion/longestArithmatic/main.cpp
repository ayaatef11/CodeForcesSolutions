#include <bits/stdc++.h>
using namespace  std;
#define ll long long
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    int n;cin>>n;
    vector<int>arr(n);

int difference;
    cin>>difference;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int ans =0;
vector<int>dp(n,1);
    for (int i=1;i<n;i++) {
        for (int j=0;j<i;j++) {
if (arr[i]-arr[j]==difference) {
    dp[i]=max(dp[i],dp[j]+1);
}

        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}