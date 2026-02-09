#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
vector<int> dp;
int solve(const vector<int>&v,int i) {
    int m=v.size();
    if (i>=m)return 0;
    if (dp[i]!=-1)return dp[i];
    int take=(i+v[i]<m)?solve(v,i+v[i]+1):1e9;
    int leave=solve(v,i+1)+1;

return dp[i]=min(take,leave);
}
int main() {
int n;cin>>n;
    while (n--) {
        int m;cin>>m;
        vector<int> v;
        for (int i=0;i<m;i++) {
            int x;cin>>x;
            v.push_back(x);
        }
        dp.assign(v.size(),-1);
        cout<<solve(v,0)<<"\n";

    }

}