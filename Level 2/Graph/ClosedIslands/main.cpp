#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Grid;
vector<vector<int>>visited;
int n,m;
void DFS(int i,int j) {
if (i<0||j<0||i>=n||j>=m||visited[i][j]||Grid[i][j]=='1') return;
    visited[i][j]=1;

    DFS(i+1,j);
    DFS(i-1,j);
    DFS(i,j+1);
    DFS(i,j-1);
}

int closedIsland(vector<vector<int>>& grid) {

}
int main() {


}