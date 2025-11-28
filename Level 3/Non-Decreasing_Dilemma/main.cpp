#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node {
    ll len;
    ll pref;
    ll suff;
    ll sum;
    ll first;
    ll last;
};
vector<Node> seg;

Node merge(const Node &L, const Node &R) {
    if (L.len == 0) return R;
    if (R.len == 0) return L;

    Node C;
    C.len =L.len+R.len;
    C.sum=L.sum+R.sum;
    if (L.last <= R.first)
        C.sum+=1LL*L.suff*R.pref;
    C.first=L.first;
    C.last=R.last;
    C.pref = L.pref;
    if (L.pref==L.len&&L.last<=R.first)
        C.pref=L.len+R.pref;

    C.suff=R.suff;
    if (R.suff == R.len &&L.last <= R.first)
        C.suff = R.len + L.suff;

    return C;
}
Node make_data(int x) {
    return {1, 1, 1, 1, x, x};
}
Node EMPTY = {0, 0, 0, 0,  LONG_LONG_MAX,LONG_LONG_MIN};

void build(int p,int l,int r,vector<ll> &a){
    if(l==r){
        seg[p]=make_data(a[l]);
        return;
    }
    int m=(l+r)/2;
    build(p*2,l,m,a);
    build(p*2+1,m+1,r,a);
    seg[p] = merge(seg[p*2], seg[p*2+1]);
}
void update(int p,int l,int r,int idx,int val){
    if(l==r){
        seg[p]=make_data(val);
        return;
    }
    int m=(l+r)/2;
    if(idx<=m) update(p*2,l,m,idx,val);
    else update(p*2+1,m+1,r,idx,val);
    seg[p]=merge(seg[p*2], seg[p*2+1]);
}

Node query(int p, int l, int r, int i, int j) {
    if (j < l || r < i) return EMPTY;
    if (i <= l && r <= j) return seg[p];

    int m = (l + r) / 2;
    Node L = query(p*2, l, m, i, j);
    Node R = query(p*2+1, m+1, r, i, j);

    return merge(L, R);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
vector<ll> a(n+1);
    seg.resize(4*n+5);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n,a);

    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            update(1, 1, n, x, y);
        } else {
            Node ans = query(1, 1, n, x, y);
            cout << ans.sum << "\n";
        }
    }

}