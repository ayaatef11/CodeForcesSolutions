#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<int>visited;
vector<vector<int>>subOrdinates;
int n;
int paths=0;
void DFS(int start) {
    int curr=start;
    if (curr == n-1){
        paths++;
        return;
    }
    for (int node:subOrdinates[curr]) {
        if (visited[node]==0) {
            visited[node]=1;
            DFS(node);
            visited[node]=0;
        }
    }
}
int main() {
    cin>>n;
    graph.resize(n);
    visited.resize(n,0);
    subOrdinates.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            subOrdinates[i].push_back(graph[i][j]);
        }
    }
    visited[0] = 1;
    DFS(0);
}