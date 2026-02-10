#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
vector<int> adj[MAX];
vector<bool> visited(MAX, false);

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) dfs(neighbor);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // قراءة الطرق الموجودة
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> components; // لحفظ المدن الرئيسية لكل مجموعة

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components.push_back(i);
            dfs(i);
        }
    }

    // عدد الطرق الجديدة المطلوبة = عدد المجموعات - 1
    cout << components.size() - 1 << "\n";

    // توصيل المجموعات ببعض
    for (int i = 1; i < (int)components.size(); i++) {
        cout << components[i - 1] << " " << components[i] << "\n";
    }

    return 0;
}
