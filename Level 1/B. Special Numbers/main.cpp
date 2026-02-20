//link : https://codeforces.com/group/isP4JMZTix/contest/405745/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<bool>visited;
vector<vector<int>> adj;
int maxPath;

void DFS(int node,int path) {
    if (visited[node]) return ;
    visited[node] = 1;
    for (auto u:adj[node]) {
        if (!visited[u]) {
            DFS(u,path+1);
        }
    }
     maxPath=max(path,maxPath);
}
int main() {
    fast();
int n;cin>>n;
adj.assign(n+1,vector<int>());
    for (int i=1;i<=n;i++) {
    int x;cin>>x;
    if (x==-1)continue;
    adj[x].push_back(i);
}
for (int i=1;i<=n;i++) {//so important
    visited.assign(n+1,false);
    DFS(i,0);
}
    cout<<maxPath+1<<ln;
}