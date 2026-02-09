#include <bits/stdc++.h>
using namespace std;
int m,n;
vector<vector<int>>grid ;
//0 is sea and 1 is land
vector<vector<bool>>visited;
int ans=0;
void DFS(int i, int j ) {
if (i<0||j<0||i>=n||j>=m)return ;

    if (visited[i][j]==true||grid[i][j]==false)return ;
    visited[i][j]=true;
    DFS(i+1,j);
    DFS(i-1,j);
    DFS(i,j+1);
    DFS(i,j-1);
}
int numEnclaves(vector<vector<int>>& gridInput) {
        grid=gridInput;
    m=grid.size();
    n=grid[0].size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if ((i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j]==1)
                DFS(i, j);
        }
        }
    }
}
int main() {

cout<<ans;

}