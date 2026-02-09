#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300000 + 5;
const int LOG = 20;

vector<int>adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];
int n, q;

void dfs(int u,int p) {
    up[u][0]=p;
    for (int i = 1; i < LOG; i++)
        up[u][i]=up[up[u][i-1]][i-1];
    for (int v:adj[u]) {
        if (v == p) continue;
        depth[v]=depth[u]+1;
        dfs(v,u);
    }
}

int kth_ancestor(int u,int k) {
    for (int i=0;i<LOG;i++)
        if (k&(1<<i))
            u=up[u][i];
    return u;
}

int lca(int a,int b) {
    if (depth[a]<depth[b])
        swap(a,b);

    int diff=depth[a]-depth[b];
    a=kth_ancestor(a, diff);

    if (a==b)return a;

    for (int i=LOG-1;i>=0;i--) {
        if (up[a][i]!=up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++)
        adj[i].clear();

    for (int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[1] = 0;
    dfs(1, 1);
    cin >> q;
    while (q--) {
        int a, b, c;
        cin>>a>>b>>c;
        int L=lca(a, b);
        int d1=depth[a]-depth[L];
        int d2=depth[b]-depth[L];
        int dist = d1 + d2;
        if (dist<=c) {
            cout<<b<< "\n";
            continue;
        }
        if (c<=d1) {
            cout<<kth_ancestor(a,c) << "\n";
        } else {
            int rem=c-d1;
            int steps_from_b=d2-rem;
            cout<<kth_ancestor(b,steps_from_b) << "\n";
        }
    }

    return 0;
}
