#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    ll evenMin,evenMax,oddMin,oddMax;
    Node() {
        evenMin = evenMax = oddMin = oddMax = 0;
    }
    Node(int x) {
        evenMin = evenMax = 0;
        oddMin = oddMax = x;
    }
    Node(const Node &lhs,const Node &rhs) {
        evenMax=max(lhs.evenMax+rhs.evenMax,lhs.oddMax-rhs.oddMin);
        evenMin=min(lhs.evenMin+rhs.evenMin,lhs.oddMin-rhs.oddMax);
        oddMax=max(lhs.evenMax+rhs.oddMax,lhs.oddMax+rhs.evenMin);
        oddMin=min(lhs.evenMin+rhs.oddMin,lhs.oddMin-rhs.evenMax);
    }
};


struct SegmentTree {
    int n;
    vector<Node> seg;

    SegmentTree(const vector<int> &a) {
        n = a.size();
        seg.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int p, int l, int r, const vector<int> &a) {
        if (l == r) {
            seg[p] = Node(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(p * 2,     l,     mid, a);
        build(p * 2 + 1, mid+1, r,   a);

        seg[p] = Node(seg[p * 2], seg[p * 2 + 1]);
    }

    void update(int p,int l, int r, int idx, int val) {
        if (l==r) {
            seg[p]=Node(val);
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
            update(p * 2, l, mid, idx, val);
        else
            update(p * 2 + 1, mid + 1, r, idx, val);

        seg[p] = Node(seg[p * 2], seg[p * 2 + 1]);
    }

    Node get(int p, int l, int r, int a, int b) {
        if (a <= l && r <= b)
            return seg[p];

        if (r < a || l > b)
            return Node();

        int mid = (l + r) / 2;
        return Node(
            get(p * 2,     l,  mid, a, b),
            get(p * 2 + 1, mid+1, r,   a, b)
        );
    }
};


void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    SegmentTree segtree(a);
    Node ans = segtree.get(1, 0, n - 1, 0, n - 1);

    cout << max(ans.evenMax, ans.oddMax) << '\n';

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        segtree.update(1, 0, n - 1, l, a[r]);
        segtree.update(1, 0, n - 1, r, a[l]);
        swap(a[l], a[r]);

        ans = segtree.get(1, 0, n - 1, 0, n - 1);
        cout << max(ans.evenMax, ans.oddMax) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}