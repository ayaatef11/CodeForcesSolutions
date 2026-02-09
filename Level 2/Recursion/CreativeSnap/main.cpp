#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> avengers;
ll a, b;
ll solve(int l, int r) {
    int na = 0;
    for (int i = l; i <= r; i++) {
        na += avengers[i];
    }
    ll len = r - l + 1;
    ll cost;
    if (na == 0) cost = a;
    else cost= b*(ll)na *(ll)len;
    if (len >= 2) {
        int mid=(l + r)/2;
        ll splitCost=solve(l, mid)+solve(mid + 1, r);
        cost = min(cost, splitCost);
    }
    return cost;
}

int main() {
    int n, k;
    cin>>n>>k>>a>>b;
    int size = 1 << n;
    avengers.assign(size + 1, 0);
    for (int i = 0; i < k; i++) {
        int pos;
        cin >> pos;
        avengers[pos]++;
    }
    cout<<solve(1, size)<< endl;
    return 0;
}
