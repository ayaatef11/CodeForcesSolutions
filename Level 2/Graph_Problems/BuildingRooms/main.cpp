#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<bool>visited;
int n,m;
void dfs(int node) {
    visited[node]=true;
    for (int neighbour:graph[node]) {
        if (!visited[neighbour])dfs(neighbour);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    graph.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> representatives;
    for (int i=1;i<=n;i++) {
        if (!visited[i]) {
            representatives.push_back(i);
            dfs(i);
        }
    }
    cout <<representatives.size()-1<<"\n";

    for (int i=1;i<representatives.size();i++) {
        cout<<representatives[i-1]<<" "<<representatives[i]<<"\n";
    }

    return 0;
}
