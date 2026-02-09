#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3;
vector<vector<int>> dp;
int solve(string& a, string& b, string& c, int i,int j,int k) {
    if (k==c.size()) {
        if (i==a.size()&&j==b.size())return 0;
        return 1e6;
    }

    if (dp[i][j]!=-1)return dp[i][j];

    int result=1e6;

    if (i<a.size()) {
        int cost=(a[i]!=c[k])?1:0;
        result=min(result,cost+solve(a,b,c,i+1,j,k+1));
    }

    if (j<b.size()) {
        int cost=(b[j]!=c[k])?1:0;
        result=min(result,cost+solve(a,b,c,i,j+1,k+1));
    }

    return dp[i][j]=result;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string a, b, c;
        cin >> a >> b >>c;
        dp.assign(a.size()+1,vector<int>(b.size()+1, -1));
        cout << solve(a, b, c, 0, 0, 0) << endl;
    }
}