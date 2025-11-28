#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>grid;
vector<vector<bool>>visited;
int n,m;
int steps;
void DFS(int i,int j) {
    if (i>=n||j>=m||i<0||j<0)return  ;
    if (!visited[i][j]||grid[i][j]==false)return ;
    visited[i][j]=true;
    DFS(i+1,j);
    DFS(i-1,j);
    DFS(i,j+1);
    DFS(i,j-1);
}

int numIslands(vector<vector<char>> &gridInputs) {
    grid=gridInputs;
    n=grid.size();
    m=grid[0].size();
    visited.assign(n,vector<bool>(m,false));

    int inslands=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j]=='1'&&!visited[i][j]) {
                DFS(i,j);
                inslands++;
            }
        }
    }
}
int main() {



}