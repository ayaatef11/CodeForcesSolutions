#include <bits/stdc++.h>
using namespace std;
int k=3;
vector<vector<int>>graph;
vector<int>res;
vector<int>root={
    // 3,5,1,6,2,0,8,-1,-1,7,4
1
};
vector<bool>visited;
void DFS(int node,int depth) {
    if (node==-1)return;
    if (visited[node])return;
    visited[node]=true;
    if (depth==k) {
        res.push_back(root[node]);
        return;
    }
    for (int neighbour:graph[node]) {
        DFS(neighbour,depth+1);
    }
}
int main() {

int target=1;
    int n=(int)root.size();
    graph.resize(n);
    visited.resize(n,false);
    for(int i=0;i<n;i++) {
        if(root[i]==-1) continue;
        int neig1=2*i+1;
        int neig2=2*i+2;
        if (neig1<n&&root[neig1]!=-1) {
            graph[i].push_back(neig1);
            graph[neig1].push_back(i);
        }
        if (neig2<n&&root[neig2]!=-1) {
            graph[i].push_back(neig2);
            graph[neig2].push_back(i);
        }
    }
    int startIdx = -1;
    for (int i = 0; i < n; i++) {
        if (root[i] == target) {
            startIdx = i;
            break;
        }
    }
    DFS(startIdx,0);
for (int i=0;i<res.size();i++) {
    cout<<res[i]<<" ";
}

}