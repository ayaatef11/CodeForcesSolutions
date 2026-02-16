//link: https://codeforces.com/group/gA8A93jony/contest/269931/problem/J
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<vector<int>> v;
vector<vector<int>>grid;
vector<vector<bool>> visited;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
void solve(int i,int j) {
    if (visited[i][j])return;
    visited[i][j] = true;
    int a=grid[i][j];
    int row = (int)v.size()-1;

    if(v.size()==0||v[row].size()==n) {
        v.emplace_back();
        row++;
    }
    v[row].push_back(a);
    if (j<n-1)solve(i,j+1);
    if (i<n-1)solve(i+1,j);
    if (j>0)solve(i,j-1);
    if (i>0)solve(i-1,j);
}
int index=0;
vector<int>flattenGrid;
void solve_spiral(int top,int bottom, int left, int right) {
    if (top>bottom || left>right)return;
    //top row
    for (int j=left;j<=right;j++) flattenGrid[index++]=grid[top][j];
    //right col
    for (int i=top+1;i<=bottom;i++)flattenGrid[index++]=grid[i][right];
    //bottom row
    if (top>=bottom)return;
    for(int j = right-1; j >= left; j--)flattenGrid[index++]=grid[bottom][j];
    if (left>=right)return;
    for (int i=bottom-1;i>top;i--)flattenGrid[index++]=grid[i][left];
    solve_spiral(top+1,bottom-1,left+1,right-1);
}
int main() {
    fast();
    cin>>n;
    grid.assign(n,vector<int>(n,0));
    v.assign(n,vector<int>(n,0));
    flattenGrid.assign(n*n,0);
    visited.assign(n,vector<bool>(n,false));
    int ind=0;
for(int i = 0; i<n; i++) {
    for(int j = 0; j<n; j++) {
        cin>>grid[i][j];
    }
}
    // solve(0,0);
    solve_spiral(0,n-1,0,n-1);
    int index2=0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
        cout<<flattenGrid[index2++]<<" ";
        }
         cout<<endl;
    }

}
