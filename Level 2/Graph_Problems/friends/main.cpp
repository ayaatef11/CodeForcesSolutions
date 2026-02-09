#include <bits/stdc++.h>
using namespace std;


void DFS(int node,int& count,vector<vector<int>>&graph,vector<int>&visited) {
visited[node]=1;
    count++;
    for (int neighbour:graph[node]) {
        if (!visited[neighbour]) {
            DFS(neighbour,count,graph,visited);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
int t;cin>>t;
    while(t--) {
        int n,m;cin>>n>>m;
vector<vector<int>>graph(n+1);
vector<int>visited(n+1,0);
        //build the graph
        for (int i=0;i<m;i++) {
            int a,b;cin>>a>>b;
            if (a==b)continue;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int maxCount=0;
        for (int i=1;i<=n;i++) {
            if (!visited[i]) {
                int count=0;
                DFS(i,count,graph,visited);
                maxCount=max(maxCount,count);
            }
        }
        cout<<maxCount<<endl;
    }

}