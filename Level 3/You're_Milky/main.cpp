#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long mn, mx;
};

vector<Node> seg;
vector<long long> A;
int N;

Node merge(Node a, Node b) {
    return{min(a.mn,b.mn),max(a.mx,b.mx)};
}

void build(int idx,int l,int r) {
    if(l==r) {
        seg[idx]={min(A[l],A[l+1]),max(A[l],A[l+1])};
        return;
    }
    int mid =(l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    seg[idx] =merge(seg[idx*2],seg[idx*2+1]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return {LLONG_MAX, LLONG_MIN};
    if(ql <= l && r <= qr) return seg[idx];
    int mid = (l+r)/2;
    return merge(query(idx*2, l, mid, ql, qr),
                 query(idx*2+1, mid+1, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int Q;
        cin >> N >> Q;
        A.resize(N+1);
        for(int i=1; i<=N; i++) cin >> A[i];

        seg.resize(4*N+5);
        build(1, 1, N-1);

        while(Q--) {
            long long U, V;
            cin >> U >> V;
            int l=1, r=N-1, ans=N;
            while(l<=r) {
                int mid = (l+r)/2;
                Node res = query(1, 1, N-1, 1, mid);
                if(res.mn <= V && V <= res.mx) {
                    ans = mid;
                    r = mid-1;
                } else l = mid+1;
            }

            if(ans == N) cout << "No\n";
            else {
                Node res = query(1, 1, N-1, 1, ans);
                if(res.mn <= U && U <= res.mx) cout << "Yes\n";
                else cout << "No\n";
            }
        }
    }
}
