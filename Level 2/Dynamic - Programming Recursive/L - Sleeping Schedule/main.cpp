#include <bits/stdc++.h>
using namespace std;

int n,h,l,r;
vector<int> a;
int dp[2005][2005];

int solve(int i,int t) {
    if(i==n)return 0;

    int &ans=dp[i][t];
    if (ans!=-1)return ans;

    ans=0;
    int t1=(t+a[i])%h;
    int good1=(t1>=l&&t1<=r);
    ans=max(ans,good1+solve(i+1,t1));

    int t2=(t+a[i]-1)%h;
    int good2=(t2>=l&&t2<=r);
    ans=max(ans,good2+solve(i+1,t2));

    return ans;
}

int main() {
    cin >>n >>h>>l>>r;
    a.resize(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0) << endl;
    return 0;
}
