#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
struct Node {
    int mini;
    int maxi;
};
vector<Node> seg;
vector<int>arr;
void build(int idx,int l, int r) {//define segments but why the index,to define the index in the seg array
    if (l==r) {
        seg[idx].mini=seg[idx].maxi=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    seg[idx].mini=min(seg[idx*2].mini,seg[idx*2+1].mini);
    seg[idx].maxi=max(seg[idx*2].maxi,seg[idx*2+1].maxi);
}

int query_min(int idx,int l,int r,int ql,int qr) {
    if (qr<l||r<ql) return INT_MAX;
    if (ql<=l&&r<=qr) return seg[idx].mini;

    int mid=(l+r)/2;
    return min(query_min(idx*2,l,mid,ql,qr),
               query_min(idx*2+1,mid+1,r,ql,qr));
}

int query_max(int idx,int l,int r,int ql,int qr) {
    if (qr<l||r<ql) return INT_MIN;
    if (ql<=l&&r<=qr) return seg[idx].maxi;

    int mid=(l+r)/2;
    return max(query_max(idx*2,l,mid,ql,qr),
               query_max(idx*2+1,mid+1,r,ql,qr));
}
int find_pos(int idx,int l,int r,int ql,int qr,int x) {
    if (qr<l||r<ql)return -1;
    if (seg[idx].mini==x&&seg[idx].maxi==x)return -1;

    if (l==r)return l;
    int mid=(l+r)/2;

    int leftAns=find_pos(idx*2,l,mid,ql,qr,x);
    if (leftAns!=-1)return leftAns;

    return find_pos(idx*2+1,mid+1,r,ql,qr,x);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    arr.resize(n+1);
    seg.resize(4*n + 5);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    build(1, 1, n);

    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;

        int mn = query_min(1, 1, n, l, r);
        int mx = query_max(1, 1, n, l, r);

        if (mn == x && mx == x) {
            cout << -1 << "\n";
        } else {
            cout << find_pos(1, 1, n, l, r, x) << "\n";
        }
    }
}