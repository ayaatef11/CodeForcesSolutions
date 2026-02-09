#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int> arr) {
    int n = arr.size();
    vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n,{0,1}));

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            dp[i][j].first = arr[j] - arr[i];
            dp[i][j].second = 2;
        }
    }

    int ans = 2;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int diff = dp[i][j].first;
            for(int k=0; k<i; k++) {
                if (dp[k][i].first == diff) {
                    dp[i][j].second = max(dp[i][j].second, dp[k][i].second + 1);
                }
            }
            ans = max(ans, dp[i][j].second);
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {9,4,7,2,10};
    cout << solve(arr);
}
