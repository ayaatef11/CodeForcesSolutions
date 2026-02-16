#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int n,m;
vector<vector<int>> v;
ll solve(int i,int j) {
    if(i==n-1 && j==m-1)
        return v[i][j];
     if(i>=n||j>=m)return -1e9;
    ll ch1=solve(i+1,j);
    ll ch2=solve(i,j+1);
    return max(ch1,ch2)+v[i][j];
}
int main() {
    fast();
    cin >> n >> m;
    v.assign(n,vector<int>(m,0));
    for(int i = 0; i <n; i++) {
        for(int j = 0; j <m; j++) {
            cin >> v[i][j];
        }
    }
  cout<<  solve(0,0);

}