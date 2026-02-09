#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,w;
vector<int>weights;
vector<ll>values;
const int MOD=1e6;
int main() {
cin>>n>>w;
    weights.resize(n);
    values.resize(n);
    for(int i=0;i<n;i++) {
        cin>>weights[i]>>values[i];
    }
vector<ll>dp(w+1,0);
    for (int i=0;i<n;i++) {
        for(int j=w;j>=weights[i];j--) {
        dp[j]=max(dp[j],dp[j-weights[i]]+values[i]);//%MOD;
        }
    }
    cout<<dp[w];
}