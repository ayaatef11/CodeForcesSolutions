#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>>board;
vector<vector<int>>vis;
int n,m;
int solve(int i,int j) {
    if (i>=n||j>=m||j<0||i<0)return 0;
    if (board[i][j]==0||vis[i][j]) return 0;
    if (i==n-1&&j==m-1)return 1;
    vis[i][j]=1;
    int total=solve(i+1,j)+solve(i,j+1)+ solve(i-1,j)+solve(i,j-1);
    //backtrack
    vis[i][j]=0;
    return total;

}

int main() {
cin>>n>>m;
board.resize(n,vector<int>(m));
    vis.resize(n,vector<int>(m,0));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>board[i][j];
        }
    }
    cout<<solve(0,0)<<endl;
}