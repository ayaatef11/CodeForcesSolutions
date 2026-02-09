#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    int caseNum = 1;

    while (true) {
        cin>>a>>b;
        if (a<0&&b<0) break;

        if (a==0&&b==0) {
            cout<<"Case "<<caseNum++<<" is a tree.\n";
            continue;
        }

        map<int,vector<int>>graph;
        map<int, int>indegree;
        set<int>nodes;
        graph[a].push_back(b);
        indegree[b]++;
        nodes.insert(a);
        nodes.insert(b);
        while (true) {
            cin>>a>>b;
            if (a==0&&b==0) break;
            graph[a].push_back(b);
            indegree[b]++;
            nodes.insert(a);
            nodes.insert(b);
        }

        bool ok=true;
        for (auto&p:indegree) {
            if(p.second>1)ok=false;
        }

        int root=-1;
        for (int node:nodes) {
            if (indegree[node]==0) {
                if (root==-1)root=node;
                else ok=false;
            }
        }

        if(root==-1)ok=false;
        set<int>visited;
        function<void(int)>dfs=[&](int u) {
            visited.insert(u);
            for (int v:graph[u])dfs(v);
        };

        if (ok)dfs(root);
        if (visited.size()!=nodes.size())ok=false;

        if (ok)
            cout << "Case " << caseNum++ << " is a tree.\n";
        else
            cout << "Case " << caseNum++ << " is not a tree.\n";
    }

    return 0;
}
