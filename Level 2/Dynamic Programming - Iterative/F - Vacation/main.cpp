#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    vector<vector<ll>> dp(n, vector<ll>(3,0));
for (int i=0;i<n;i++) {
    cin >> v[i][0] >> v[i][1] >> v[i][2];
}
    dp[0][0]=v[0][0];
    dp[0][1]=v[0][1];
    dp[0][2]=v[0][2];
    for (int i=1;i<n;i++) {
        for (int j=0;j<3;j++) {
            int a=j-1;
            int b=j-2;
            if (a<0)a+=3;
            if (b<0)b+=3;
            dp[i][j] = v[i][j]+max(dp[i-1][a], dp[i-1][b]);
        }
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

}