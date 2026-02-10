#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300000 + 5;
const int LOG = 20;

vector<pair<int,int>> adj[MAXN];
int parent[MAXN][LOG];
long long minEdge[MAXN][LOG];
int depth[MAXN];
int n, m, q;

void dfs(int u, int p, long long w) {
    parent[u][0] = p;
    minEdge[u][0] = w;
    for (auto &nx : adj[u]) {
        int v = nx.first;
        long long ww = nx.second;
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u, ww);
    }
}

long long lift(int &u, int k) {
    long long res = LLONG_MAX;
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            res = min(res, minEdge[u][i]);
            u = parent[u][i];
        }
    }
    return res;
}

long long query(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    long long ans = LLONG_MAX;
    ans = min(ans, lift(a, depth[a] - depth[b]));

    if (a == b) return ans;

    for (int i=LOG-1;i>=0;i--) {
        if (parent[a][i] != parent[b][i]) {
            ans = min(ans, minEdge[a][i]);
            ans = min(ans, minEdge[b][i]);
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    ans = min(ans, minEdge[a][0]);
    ans = min(ans, minEdge[b][0]);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    for (int i=0;i<m;i++) {
        int u,v;
        long long w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    depth[1]=0;
    dfs(1,0,LLONG_MAX);
    for (int j=1;j<LOG;j++) {
        for (int i=1;i<=n;i++) {
            int p=parent[i][j-1];
            parent[i][j]=parent[p][j - 1];
            minEdge[i][j]=min(minEdge[i][j-1],minEdge[p][j-1]);
        }
    }
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << "\n";
    }
}
