#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> tree;
int size_tree;

long long build(vector<long long>&a,int node,int l,int r,bool level) {
    if(l == r) return tree[node] = a[l];
    int mid = (l+r)/2;
    long long left=build(a,node*2,l,mid,!level);
    long long right=build(a,node*2+1,mid+1,r,!level);
    if(level) return tree[node] = left | right;
    else return tree[node] = left ^ right;
}

long long update(int node,int l,int r,int idx,long long val,bool level) {
    if(l==r)return tree[node]=val;
    int mid =(l+r)/2;
    long long left,right;
    if(idx<=mid)left=update(node*2, l, mid, idx, val, !level), right = tree[node*2+1];
    else right=update(node*2+1, mid+1, r, idx, val, !level), left = tree[node*2];
    if(level) return tree[node] = left | right;
    else return tree[node] = left ^ right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin>>n>>m;
    int N=1<<n;
    vector<long long>a(N+1);
    for(int i=1;i<=N;i++)cin>>a[i];
    tree.resize(4*N);

    bool level=(n%2==1);
    build(a,1,1,N,level);

    while(m--) {
        int p;
        long long b;
        cin>>p>>b;
        update(1,1,N,p,b,level);
        cout<<tree[1]<< "\n";
    }
}
