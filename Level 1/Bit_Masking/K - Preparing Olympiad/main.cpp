#include <bits/stdc++.h>
using namespace std;
int n,l,r,x;
vector<int> v;
int solve(int i,int sum ,int first,int last) {
    if (i==v.size() ) {
        if (sum>=l && sum<=r && last-first>=x)return 1;
        return 0;
    }
   return solve(i+1,sum+v[i],min(first,v[i]),max(last,v[i]))
          +solve(i+1,sum,first,last);
}
int main() {
cin >> n >> l >> r >> x;
v.assign(n,0);
    for (int i = 0; i <n; i++)cin>>v[i];
    cout << solve(0,0,INT_MAX,0) << endl;
}