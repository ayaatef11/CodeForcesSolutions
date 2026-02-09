#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<int>visited;
int n,m;
bool isCyclic(int node) {//for directed graph
    if (visited[node]==1)return true;
    if (visited[node]==2)return false;
    visited[node]=1;//mark it as visited
    for (int neighbour : graph[node])
   if (isCyclic(neighbour))return true;
    visited[node]=2;
    return false;
}

//for undirected graph
bool hasCycle(int node,int start) {
    visited[node]=true;
    for (int neighbour:graph[node]) {
        if (!visited[neighbour]) {
            if (hasCycle(neighbour, node))
                return true;
        }
        else if (neighbour != start)
            return true;
    }
    return false;
}
void dfs(int node) {
    visited[node] = true;
    for (int neighbour : graph[node]) {
        if (!visited[neighbour])
            dfs(neighbour);
    }
}
bool isConnected() {
    dfs(1);
    for (int i=1;i<=n;i++) {
        if (!visited[i])return false;

    }
    return true;
}
int main() {
cin>>n>>m;
graph.resize(n+1);
    visited.resize(n+1,0);
    //build the graph
    for (int i=0;i<m;i++) {
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //check edges and nodes
    if (m!=n-1) {
        cout<<"NO";
        return 0;
    }
    if (hasCycle(1,-1)) {
        cout<<"NO";
        return 0;
    }
//make visited is 0 again
    fill(visited.begin(),visited.end(),false);
    if (!isConnected()) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
}