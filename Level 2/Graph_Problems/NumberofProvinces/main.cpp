#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> graph;
vector<bool>visited;
void dfs(int node) {
    visited[node]=true;
    for (int i=0;i<n;i++) {
if (graph[node][i]==1 && !visited[i]) {
    dfs(i);
}
    }
}
int main() {
   cin>>n;
    graph.resize(n,vector<int>(n));
    visited.resize(n,false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>graph[i][j];
        }
    }
    int cnt=0;
    for (int i = 0; i < n; i++) {
        if (visited[i]==false){
            dfs(i);
            cnt++;
        }
    }
cout<<cnt;

}