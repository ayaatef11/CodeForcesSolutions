#include <bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map<int,int>cnt;
vector<int> keys;
vector<ll> dp;
ll solve(int i) {
    if (i>=keys.size())return 0;
    if (dp[i]!=-1)return dp[i];
    ll leave=solve(i+1);
    ll take=1LL* keys[i]*cnt[keys[i]];

    if (i+1<keys.size()&&keys[i+1]==keys[i]+1)
        take+=solve(i+2);
    else
        take+=solve(i+1);

    return dp[i]=max(take,leave);
}

int main() {
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        cnt[arr[i]]++;
    }
    for (auto &p:cnt)
        keys.push_back(p.first);
    dp.assign(keys.size(),-1);

    sort(keys.begin(),keys.end());
    cout<<solve(0);
}