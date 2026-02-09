#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int from, to,weight;
};
int n,m;
vector<bool>visited;
vector<vector<pair<int,int>>>adje(n+1);
bool flag;
void DFS(int u) {//it is from source , the root for tree for example
   visited[u]=true;
    for (pair<int,int> v:adje[u]) {
        if (not visited[v.first]) {
            DFS(v.first);
        }
    }
}
void DetectCycle(int u,int par) {//it is from source , the root for tree for example
    visited[u]=true;
    for (pair<int,int> v:adje[u]) {
        if (v.first==par) {continue;}
        if (not visited[v.first]) {
            DFS(v.first);
        }
    }
}
void dfsTree(int u,int par) {
    for (pair<int,int> v:adje[u]) {
        if (v.first==par)continue;;
        dfsTree(v.first,u);
    }
}
int main() {

//the first way -- adjacecny matrix undirected graph
    cin>>n>>m;
    vector<vector<int>>adj(n+1,vector<int>(n+1,-1));
    for (int i=0,u,v,w;i<m;i++) {
        cin>>u>>v>>w;
        adj[u][v]=w;
        adj[v][u]=w;
    }
    //the second way adjacency list every node has list of adjacency nodes
for(int i=0,u,v,w;i<m;i++) {
    cin>>u>>v>>w;
    adje[u].emplace_back(v,w);//node and its weight
    adje[v].emplace_back(u,w);
}
    visited.assign(n+1,false);
    //the third way the edge list
    vector<array<int,3>>edgeList(m);//or vector< Edge>
    for(auto &[u,v,w]:edgeList) {
        cin>>u>>v>>w;
    }
//number  of connected components
    int cnt=0;
for ( int i=0;i<visited.size();i++) {
    if (!visited[i]) {DFS(i);cnt++;}
}
    flag=false;
    for ( int i=0;i<visited.size();i++) {
if (visited[i])continue;
        DetectCycle(i,-1);
        if (flag)cout<<"yes";

    }
}