#include <bits/stdc++.h>
using  namespace std;
const int MAX_SIZE=2e5+4;
const int MOD=1e9+7;
int n,m;
vector<int>adj[MAX_SIZE],indegree(MAX_SIZE+1);
int memo[MAX_SIZE];
vector<int>toposort;

int longest_path_recursive(int u) {
    if (memo[u]!=-1)return memo[u];
    auto &ret=memo[u];
    ret=1;
    for (auto v: adj[u]) {
        ret=max(ret,1+longest_path_recursive(v));
    }
    return ret;
}
//ok we need our nodes to be sorted from the ready not to the not ready one
//if we have an edge directed a->b then a is ready, b depends on it
// so we will do topological sort and store nodes in reverse order

int longest_path_iterative() {
    vector<int>dp(n+1);
   for (int i=0;i<n;i++) {
       int u=toposort[i];
       dp[u]=1;
       for (auto v: adj[u]) {
           dp[u]=max(dp[u],1+dp[v]);
       }
   }
    int mx=0;
    for (int i=1;i<=n;i++) {mx = max(mx,dp[i]);}
    return mx-1;//because he want the number of edges not the number of nodes
}

int main() {
cin>>n>>m;
    for (int i=0;i<m;i++) {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    queue <int>q;
    for (int i=1;i<=n;i++) {
        if (!indegree[i])q.push(i);
    }
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        toposort.push_back(u);
        for (auto v: adj[u]) {
            indegree[v]--;
            if (indegree[v]==0)q.push(v);
        }
    }

}