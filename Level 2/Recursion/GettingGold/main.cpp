#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum, pref, suff, ans;
};

const long long NEG_INF = -1e18;

vector<Node> seg;
vector<long long> arr;
int n, m;

Node merge(Node left, Node right) {
    Node result;
    result.sum = left.sum + right.sum;
    result.pref = max(left.pref, left.sum + right.pref);
    result.suff = max(right.suff, right.sum + left.suff);
    result.ans = max({left.ans, right.ans, left.suff + right.pref});
    return result;
}

Node make_node(long long val) {
    Node result;
    result.sum = val;
    result.pref = result.suff = result.ans = max(val, 0LL);
    return result;
}

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = make_node(arr[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);
    seg[idx] = merge(seg[idx*2], seg[idx*2+1]);
}

void update(int idx, int l, int r, int pos, long long val) {
    if (l == r) {
        seg[idx] = make_node(val);
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(idx*2, l, mid, pos, val);
    else update(idx*2+1, mid+1, r, pos, val);
    seg[idx] = merge(seg[idx*2], seg[idx*2+1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    seg.resize(4*n);
    build(1, 0, n-1);

    // نطبع قبل أي عملية
    cout << seg[1].ans << "\n";

    while (m--) {
        int i;
        long long v;
        cin >> i >> v;
        update(1, 0, n-1, i, v);
        cout << seg[1].ans << "\n";
    }

    return 0;
}
