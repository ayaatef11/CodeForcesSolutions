#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>visited;
vector<vector<int>> graph;
int n,m;
vector<int>prices;
int minPrice;
void DFS(int node) {
    visited[node] = true;
    minPrice=min(minPrice,prices[node-1]);
    for (int neighbour:graph[node]) {
        if (!visited[neighbour]) {
            DFS(neighbour);
        }
    }
}

signed main() {
cin>>n>>m;
    graph.resize(n+1);
    prices.resize(n);
    visited.resize(n+1);
    for (int i = 0; i < n; i++) {
        cin>>prices[i];
    }
for (int i=0;i<m;i++) {//edges
    int a,b;cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
}
    int totalPrice=0;
    //build the dfs using stack to overcome overflow
    for (int start=1;start<=n;start++) {
        if (visited[start]) continue;
        int minPrice=LLONG_MAX;
        stack<int>st;
        st.push(start);
        visited[start]=true;
        while (!st.empty()) {
            int node=st.top();
            st.pop();
            minPrice=min(minPrice,prices[node-1]);
            for (int neighbour:graph[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour]=true;
                    st.push(neighbour);
                }
            }
        }
        totalPrice+=minPrice;
    }

    cout<<totalPrice<<endl;
}