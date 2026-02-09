#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>graph;
vector<bool>visited;
queue<int>q;
void BFS(int j) {
    q.push(j);
    visited[j]=true;
    while (!q.empty()) {
        int next=q.front();
        q.pop();
        for (int i=0;i<graph[next].size();i++) {
            int node=graph[j][i];
            if (!visited[node]) {
                visited[node]=true;
                q.push(node);
            }
        }
    }
}
int main() {
    cin>>n;
    graph.resize(n);
    graph={{1,3},{3,0,1},{2},{0}};

    BFS(0);
    for (int i=0;i<visited.size();i++) {
        if (!visited[i]) {
            cout<<'0';return;
        }
    }
    cout<<1<<endl;
}





