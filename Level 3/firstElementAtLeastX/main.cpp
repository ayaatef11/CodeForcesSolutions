#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long mx;
};

vector<Node> seg;
vector<long long> arr;
int n, m;

Node mergeNode(const Node &L, const Node &R) {
    Node res;
    res.mx = max(L.mx, R.mx);
    return res;
}

Node make_node(long long val) {
    Node res;
    res.mx = val;
    return res;
}

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = make_node(arr[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(idx<<1, l, mid);
    build(idx<<1|1, mid+1, r);
    seg[idx] = mergeNode(seg[idx<<1], seg[idx<<1|1]);
}

void update(int idx, int l, int r, int pos, long long val) {
    if (l == r) {
        seg[idx] = make_node(val);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(idx<<1, l, mid, pos, val);
    else update(idx<<1|1, mid+1, r, pos, val);
    seg[idx] = mergeNode(seg[idx<<1], seg[idx<<1|1]);
}

// return minimum index j in [l..r] with a[j] >= x, or -1 if none
int find_first(int idx, int l, int r, long long x) {
    if (seg[idx].mx < x) return -1; // no element in this segment meets the requirement
    if (l == r) return l;
    int mid = (l + r) >> 1;
    // try left child first to get minimum index
    if (seg[idx<<1].mx >= x) return find_first(idx<<1, l, mid, x);
    return find_first(idx<<1|1, mid+1, r, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    arr.assign(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    seg.assign(4*n + 5, Node{LLONG_MIN});

    build(1, 0, n-1);

    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            long long v;
            cin >> i >> v;
            update(1, 0, n-1, i, v);
        } else if (t == 2) {
            long long x;
            cin >> x;
            int ans = find_first(1, 0, n-1, x);
            cout << ans << '\n';
        }
    }
    return 0;
}
