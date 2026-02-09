#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> tree;
    int n;
    BIT(int _n) : n(_n) { tree.assign(n+2,0); }

    void update(int idx,int val){
        while(idx<=n){
            tree[idx]+=val;
            idx+=idx&-idx;
        }
    }

    int query(int idx){
        int res=0;
        while(idx>0){
            res+=tree[idx];
            idx-=idx&-idx;
        }
        return res;
    }

    int range(int l,int r){
        return query(r)-query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> b=a;
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++)
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;

    BIT bitLeft(n), bitRight(n);
    vector<long long> leftCount(n), rightCount(n);
    for(int i=n-1;i>=0;i--){
        rightCount[i]=bitRight.query(a[i]-1);
        bitRight.update(a[i],1);
    }
    long long res=0;
    for(int i=0;i<n;i++){
        leftCount[i]=bitLeft.query(n)-bitLeft.query(a[i]);
        bitLeft.update(a[i],1);
        res += leftCount[i]*rightCount[i];
    }

    cout << res << "\n";
}
