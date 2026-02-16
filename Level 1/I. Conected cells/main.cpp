#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int n,m;
int cnt=0;
vector<vector<bool>>visited;
vector<vector<char>>grid;
void solve(int i,int j) {
    if (!visited[i][j]){//as the neighboring nodes may be visited
        visited[i][j]=true;
    }
    else return ;
    if (i<n-1 && grid[i+1][j]==grid[i][j]) solve(i+1,j);
    if (i>0 && grid[i-1][j]==grid[i][j]) solve(i-1,j);
    if (j<m-1 && grid[i][j+1]==grid[i][j]) solve(i,j+1);
    if (j>0 && grid[i][j-1]==grid[i][j]) solve(i,j-1);
}
int main() {
    fast();
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    visited.assign(n, vector<bool>(m));
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
    }
}
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                solve(i,j);
                cnt++;
            }
        }
    }
    cout << cnt;
}