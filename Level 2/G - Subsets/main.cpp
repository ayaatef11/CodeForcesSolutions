#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>a;
vector<string>ans;
void solve(int i,string s) {
    if (i>=n) {
      ans.push_back(s);
        return;
    }
    solve(i+1,s+to_string(a[i])+" ");
    solve(i+1,s);
}
int main() {
cin>>n;
    a.assign(n,0);
    for (int i = 0; i < n; i++)cin>>a[i];
    solve(0,"");
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)cout<<ans[i]<<endl;
}