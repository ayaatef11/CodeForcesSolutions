#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nums[10]={0,1,2,3,4,5,6,7,8,9};
vector<int> v(10);
int k;
int total=0;
int maxi=0;
vector<int>vis(10,0);
vector<int> result;
vector<int>res;
void solve(int i) {
    if (total>k)return;
    if (i==10) {
        if (total<=k&&total>maxi) {
            maxi=total;
            res=result;
    }
        return;
    }
    for (int j=0;j<10;j++) {
        if (vis[j])continue;
        vis[j]=1;
        total+=nums[j]*v[i];
        result.push_back(nums[j]);

        solve(i+1);
        total-=nums[j]*v[i];
        result.pop_back();
        vis[j]=0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
int t;cin>>t;
    while(t--) {
        for (int i=0;i<10;i++) cin>>v[i];
        cin>>k;
        total = 0;
        maxi = 0;
        res.clear();
        result.clear();
        fill(vis.begin(), vis.end(), 0);
        solve(0);
        if (res.size()==0)cout<<-1;
        else
        for (int i=0;i<10;i++) cout<<res[i]<<" ";
        cout<<endl;
    }

}