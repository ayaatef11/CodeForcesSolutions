#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<pair<int,int>>>graph;//for weighted graph
int n,m;
vector<bool>visited;
vector<pair<int,int>>selectedEdges;
int maxWeight=0;
bool find(int v, int w) {
    for (int i =0;i<selectedEdges.size(); i++) {
        if (v==selectedEdges[i].first && w==selectedEdges[i].second) return true;
    }
    return false;
}
int primAlgorithm() {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    int finalWeight=0;
    while (!pq.empty()) {
        auto [w,v]=pq.top();
        pq.pop();
        if (visited[v])continue;
        finalWeight+=w;
        if (w>maxWeight) {maxWeight=w;}
        visited[v]=1;
        selectedEdges.push_back({v,w});
        for (int j=0;j<graph[v].size();j++) {
            int currentNode=graph[v][j].first;
            int weight=graph[v][j].second;
            if (!visited[currentNode]) {
                pq.push({weight,currentNode});
            }

        }

    }
    return finalWeight;
}
int main() {
    cin>>n>>m;
    graph.resize(n+1);
visited.resize(n+1,0);
    vector<tuple<int,int,int>>edges;
    for (int i=0;i<m;i++) {
        int a,b,c;cin>>a>>b>>c;
        edges.push_back({a,b,c});
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

  int minimumWeight= primAlgorithm();
    for (int i=0;i<edges.size();i++) {
        int v = get<0>(edges[i]);
        int w = get<2>(edges[i]);
        if (find(v,w))cout<<minimumWeight;
        else cout<<minimumWeight+w-maxWeight<<endl;
    }
}