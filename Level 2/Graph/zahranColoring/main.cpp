#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<int>colors;
bool found;
void BFS(int start) {
    queue<int>q;
    q.push(start);
    colors[start] = 1;//the colors is 2 and sums is3
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int node:graph[u]) {
            if (colors[node] == -1) {
                colors[node]=3-colors[u];
                q.push(node);
            }else if (colors[node] == colors[u]) {
                found=true;
            }
        }
    }
}
int main() {
int t;cin>>t;
    while(t--) {
        int n;cin>>n;
        graph.assign(n+1,{});
        colors.assign(n+1,-1);
        found=false;
        vector<int> freq(n+1,0);
        for (int i=0;i<n;i++) {
            int a,b;cin>>a>>b;
            if(a==b)found=true;
            freq[a]++;
            freq[b]++;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(freq[i]>2)found=true;
        }
        for (int i=1;i<=n;i++) {
            if (colors[i]==-1) {
                BFS(i);
            }
        }
if (found) {
    cout<<"NO"<<endl;
}else cout<<"YES"<<endl;
    }

}