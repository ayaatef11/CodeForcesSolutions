#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int,int>>> graph;
vector<bool>visited;
int changes = 0;
void DFS(int node) {
    visited[node]=true;
    for (auto&[next,needsChange]:graph[node]) {
        if (!visited[next]) {
            changes+=needsChange;
            DFS(next);
        }
    }
}

int main() {
    cin >> n;
    vector<vector<int>> connections(n - 1, vector<int>(2));
    graph.resize(n);
    visited.resize(n, false);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        connections[i][0] = a;
        connections[i][1] = b;
        graph[a].push_back({b, 1});
        graph[b].push_back({a, 0});
    }

    DFS(0);

    cout << changes << endl;
}
