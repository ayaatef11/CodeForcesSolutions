#include <bits/stdc++.h>
using namespace std;
vector<bool>visited;
vector<vector<int>>graph;
int countt =0;
int n,m;
 bool isCyclic(int node, int parent) {
  visited[node]=true;
  // if (node==parent)return true;
  for (int neighbour: graph[node]) {
  if (!visited[neighbour]) {
   if (isCyclic(neighbour,node)) {return true;}
   }
else if (neighbour!=parent) {
 return true;
}
  }
  return false;
 }

void dfs(int node) {
  visited[node]=true;
  countt++;
  for (int neighbour: graph[node]) {
   if (!visited[neighbour]) {
    dfs(neighbour);
   }
  }
 }

bool isConnected() {
  dfs(1);
  for (int i=1;i<=n;i++) {
   if (!visited[i]) {return false;}
  }
  return true;
 }

bool isBusTopology() {
 if(m!=n-1)return false;
  if(!isConnected())return false;
//check nodes degree
 int endPoints=0;
 for (int i=1;i<= n;i++) {
  int deg=graph[i].size();
  if (deg==1)endPoints++;//start node or end node has degree one
  else if (deg!=2) return false;
 }

 return endPoints == 2;
}

bool isStarTopology() {
  if(m!=n-1)return false;
  int countLeaves=0;
  int counterCenter=0;
  for (int i=1;i<=n;i++) {
   if (graph[i].size()==n-1)counterCenter++;
   else if (graph[i].size()==1) {countLeaves++;}
   else return false;
  }
  if (countLeaves==n-1&&counterCenter==1) {return true;}
  return false;
 }
bool isRingTopology() {
  if(m!=n)return false;
  for (int i = 1; i <= n; i++) {
   if (graph[i].size() != 2) {
    return false;
   }
  }
  fill(visited.begin(), visited.end(), false);

  dfs(1);
  if (countt!=n)return false;
  return true;

 }
int main() {
ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  graph.assign(n+1,{});
  visited.assign(n+1,{false});
  for(int i=0;i<m;i++) {
   int a,b;cin>>a>>b;
   graph[a].push_back(b);
   graph[b].push_back(a);
  }
if(isBusTopology()) {
 cout<<"bus topology"<<endl;
}
  else if (isRingTopology())cout<<"ring topology"<<endl;
  else if (isStarTopology())cout<<"star topology"<<endl;
  else cout<<"unknown topology"<<endl;
}