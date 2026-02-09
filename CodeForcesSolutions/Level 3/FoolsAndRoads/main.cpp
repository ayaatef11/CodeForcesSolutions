#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int LOG = 20;

vector<int> adj[N];
int up[N][LOG];
int depth[N];
int cnt[N];
int n;

void dfs(int u,int p) {
    up[u][0]=p;
    for (int i=1;i<LOG;i++)
        up[u][i]=up[up[u][i-1]][i-1];

    for (int v:adj[u]) {
        if (v==p) continue;
        depth[v]=depth[u]+1;
        dfs(v,u);
    }
}

int lca(int a,int b) {
    if (depth[a]<depth[b])swap(a,b);

    int diff=depth[a]-depth[b];
    for (int i=0;i<LOG;i++)
        if (diff&(1<<i))
            a=up[a][i];

    if (a==b) return a;

    for (int i=LOG-1;i>=0;i--) {
        if (up[a][i]!=up[b][i]) {
            a=up[a][i];
            b=up[b][i];
        }
    }

    return up[a][0];
}

void dfs2(int u,int p,vector<int>&answer,vector<pair<int,int>>&edges) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs2(v, u, answer, edges);
        cnt[u] += cnt[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<pair<int,int>> edges;

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    depth[1] = 0;
    dfs(1, 1);

    int k;
    cin >> k;

    while (k--) {
        int a, b;
        cin >> a >> b;
        int c = lca(a, b);

        cnt[a] += 1;
        cnt[b] += 1;
        cnt[c] -= 2;
    }

    vector<int> answer(n);

    dfs2(1, 1, answer, edges);
    for (auto &e : edges) {
        int u = e.first, v = e.second;

        if (depth[u] > depth[v]) swap(u, v);
        cout << cnt[v] << " ";
    }
}
