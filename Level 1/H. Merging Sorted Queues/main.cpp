#include <bits/stdc++.h>
#define ll long long
#define ln '\n'
using namespace std;
int n,m;
vector<int>a,b;
vector<int>c;
vector<vector<int>>res;
void solve(int i , int j,int last) {
    bool ok=false;
    if (i<n && a[i]>last) {
        c.push_back(a[i]);
        solve(i+1,j,a[i]);
        c.pop_back();
        ok=true;
    }
    if (j<m && b[j]>last) {
        c.push_back(b[j]);
        solve(i,j+1,b[j]);
        c.pop_back();
        ok=true;
    }
    if (!ok && !c.empty()) {
       res.push_back(c);
    }
}
int main() {
cin>>n;
    a.assign(n,0);
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>m;
    b.assign(m,0);
    for(int i=0;i<m;i++)cin>>b[i];
solve(0,0,0);
    sort(res.begin(),res.end());
    for (auto i:res) {
        for (auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
}