#include <bits/stdc++.h>
using namespace std;
#define int long long
map<long long, vector<long long>> graph;
map<long long, bool> visited;
void bfs(int start) {
    queue<int>q;q.push(start);
    visited[start]=true;

    while(!q.empty()) {
        int node= q.front();q.pop();
        cout<<node<<" ";
        for(int neigh:graph[node]) {
            if(!visited[neigh]) {
                visited[neigh]=true;
                q.push(neigh);
            }
        }
    }
}

signed main() {
    int n;cin>>n;

    for(int i=0;i<n;i++) {
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start=-1;
    for(auto node:graph) {
        if(node.second.size()==1) {
            start=node.first;
            break;
        }
    }
    bfs(start);

    return 0;
}
