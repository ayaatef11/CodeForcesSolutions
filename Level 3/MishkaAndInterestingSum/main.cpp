#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Node {
    unordered_map<int,int>repetitions;
};
vector<Node> seg;
vector<ll>a;

Node merge(Node& l, Node& r) {
    Node c=l;

    for (auto &[num, par] : r.repetitions) {
    c.repetitions[num]+=par;
    }
return c;
}
int getResult(Node& c) {
    ll result =0;
    for (auto &[num, par] : c.repetitions) {
        if (par%2==0) {
            result^=num;
        }
    }
return result;
}

void build(int l, int r,int idx) {
    if (l==r) {
        seg[idx].repetitions[a[l]]=1;
        return ;
    }
    int m = (l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    seg[idx]= merge(seg[idx*2],seg[idx*2+1]);
}
Node query(int idx, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return Node();
    if (ql <= l && r <= qr) return seg[idx];
    int mid = (l + r) / 2;
    Node left = query(idx*2, l, mid, ql, qr);
    Node right = query(idx*2+1, mid+1, r, ql, qr);
    return merge(left, right);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    seg.resize(4*n);
    build(0, n-1, 1);

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        Node res = query(1, 0, n-1, l, r);
        int ans = getResult(res);
        cout << ans << "\n";
    }
}