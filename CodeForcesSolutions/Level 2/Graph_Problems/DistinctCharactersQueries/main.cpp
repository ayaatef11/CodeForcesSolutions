#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node {
    int mask;//bitmask for characters
};
string s;
vector<Node> seg;
int n,q;
Node merge(Node a, Node b) {
    return Node{a.mask | b.mask};
}

void build(int idx,int l, int r) {
    if (l==r) {
        int bit=s[l]-'a';
        seg[idx].mask =(1<<bit);
        return;
    }
    int mid = (l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    seg[idx] =merge(seg[idx*2],seg[idx*2+1]);
}
void update(int idx,int l, int r, int pos, int c) {
    if (l==r) {
        int bit=c-'a';
        seg[idx].mask = 1<<bit;
        return;
    }
    int mid = (l+r)/2;
    if (pos<=mid) update(idx*2,l,mid,pos,c);
    else update(idx*2+1,mid+1,r,pos,c);
    seg[idx]=merge(seg[idx*2],seg[idx*2+1]);
}
int query(int idx,int l,int r,int ql,int qr) {
    if (qr<l||r<ql) return 0;
    if (ql<=l&&r<=qr) return seg[idx].mask;

    int mid=(l+r)/2;
    int leftMask=query(idx*2,l,mid,ql,qr);
    int rightMask=query(idx*2+1,mid+1,r,ql,qr);
    return leftMask | rightMask;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    n=s.size();
    s =" " +s;
    seg.resize(4*n +5);
    build(1,1,n);
    cin>>q;
    while(q--) {
        int type;
        cin>>type;
        if(type==1) {
            int pos;
            char c;
            cin>>pos>>c;
            update(1,1,n,pos,c);

        } else {
            int l,r;
            cin>>l>>r;
            int mask=query(1,1,n,l,r);
            cout<< __builtin_popcount(mask) << "\n";
        }
    }

}