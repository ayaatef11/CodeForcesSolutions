#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
const int LOG = 20;

vector<int> adj[MAXN+5];
int up[MAXN+5][LOG];
int depth[MAXN+5];
int n, q;

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; i++)
        up[u][i] = up[ up[u][i-1] ][i-1];

    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    int k = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++)
        if (k & (1 << i))
            u = up[u][i];

    if (u == v)
        return u;

    for (int i = LOG-1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int dist(int u, int v) {
    int w = lca(u, v);
    return depth[u] + depth[v] - 2*depth[w];
}

int compute(int f, int x, int y) {
    int d1 = dist(f, x);
    int d2 = dist(f, y);
    return min(d1, d2) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    depth[1] = 0;
    dfs(1, 1);

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;

        int ans = 1;
        ans = max(ans, compute(a, b, c));
        ans = max(ans, compute(b, a, c));
        ans = max(ans, compute(c, a, b));

        cout << ans << "\n";
    }

    return 0;
}
