#include <bits/stdc++.h>
using namespace std;
int cnt=0;
vector<vector<int>> v;
int n,m;
void dfs(int x) {
    if (x>=n)return ;
    for (int i = 0; i < m; i++) {
        if (!v[x][i]) {
            cnt++;
break;
        }
    }
     dfs(x+1);
}
int main() {
    cin>>n>>m;
    v.resize(n,vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>v[i][j];
        }
    }
    dfs(0);
    cout<<cnt;
}