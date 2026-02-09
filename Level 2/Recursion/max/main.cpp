#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;cin>>n;
vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
     cin>>v[i].first>>v[i].second;
    }
    vector<int> dp(n+1,1);
    int ans=0;
    sort(v.begin(), v.end());
    for (int i=1;i<n;i++) {
        for (int j=0;j<i;j++) {
            if (v[i].first>v[j].first && v[i].first>v[j].second) {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}