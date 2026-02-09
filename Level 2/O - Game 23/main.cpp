#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans=-1;
void solve(int x,int moves) {
    if (x>m)return ;
    if (x==m) {
        ans=moves;
    }
    solve(x*2,moves+1);
    solve(x*3,moves+1);
}
int main() {
cin>>n>>m;

  solve(n,0);
    cout<<ans<<endl;
}