#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pairs;
    int open;
    int close;
    Node(int p=0,int o=0,int c=0): pairs(p), open(o), close(c) {}
};

string s;
vector<Node> seg;

Node combine(const Node &L, const Node &R) {
    Node res;
    int matched = min(L.open, R.close);
    res.pairs = L.pairs + R.pairs + matched;
    res.open  = L.open + R.open - matched;
    res.close = L.close + R.close - matched;
    return res;
}

void build(int idx, int l, int r) {
    if (l == r) {
        if (s[l-1] == '(') seg[idx] = Node(0,1,0);
        else seg[idx] = Node(0,0,1);
        return;
    }
    int mid = (l + r) >> 1;
    build(idx<<1, l, mid);
    build(idx<<1|1, mid+1, r);
    seg[idx] = combine(seg[idx<<1], seg[idx<<1|1]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return Node(0,0,0);
    if (ql <= l && r <= qr) return seg[idx];
    int mid = (l + r) >> 1;
    if (qr <= mid) return query(idx<<1, l, mid, ql, qr);
    if (ql > mid) return query(idx<<1|1, mid+1, r, ql, qr);
    Node leftRes = query(idx<<1, l, mid, ql, qr);
    Node rightRes = query(idx<<1|1, mid+1, r, ql, qr);
    return combine(leftRes, rightRes);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> s)) return 0;
    int n = (int)s.size();
    int m;
    cin >> m;
    seg.assign(4*n + 5, Node());
    build(1, 1, n);

    while (m--) {
        int l, r;
        cin >> l >> r;
        Node ans = query(1, 1, n, l, r);
        cout << (ans.pairs * 2) << '\n';
    }
    return 0;
}
