#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

int n, m;
vector<int> seg; // segment tree

void build(vector<int> &a, int node, int l, int r) {
    if (l == r) {
        seg[node] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(a, 2 * node, l, mid);
        build(a, 2 * node + 1, mid + 1, r);
        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }
}

void update(int node, int l, int r, int pos, int val) {
    if (l == r) {
        seg[node] = val;
    } else {
        int mid = (l + r) / 2;
        if (pos <= mid) update(2 * node, l, mid, pos, val);
        else update(2 * node + 1, mid + 1, r, pos, val);
        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }
}

int query(int node, int l, int r, int x, int start_index) {
    // لو الماكس في هذا الجزء أصغر من x → مفيش حل هنا
    if (seg[node] < x) return -1;

    if (l == r) return l;

    int mid = (l + r) / 2;

    // لو start_index ≤ mid → يمكن نلاقي الإجابة في الجزء الشمال
    if (start_index <= mid) {
        int left_ans = query(2 * node, l, mid, x, start_index);
        if (left_ans != -1) return left_ans;
    }

    // لو ملاقيناش، ندور في اليمين
    return query(2 * node + 1, mid + 1, r, x, start_index);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    seg.resize(4 * n);
    build(a, 1, 0, n - 1);

    while (m--) {
        int type;
        cin >> type;

        if (type == 1) {
            int i, v;
            cin >> i >> v;
            update(1, 0, n - 1, i, v);
        }
        else {
            int x, l;
            cin >> x >> l;
            cout << query(1, 0, n - 1, x, l) << "\n";
        }
    }
    return 0;
}
