#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string>grid;
vector<vector<bool>>visited;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool isValid(int x,int y) {
    return x>=0&&x<n&&y>=0&&y<m;
}
void bfs(int startX,int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY]=true;
    while (!q.empty()) {
        auto[x,y]=q.front();
        q.pop();
        for (int dir=0;dir<4;dir++) {
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if (isValid(nx, ny)&&!visited[nx][ny]&&grid[nx][ny]=='.') {
                visited[nx][ny]=true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++) {
        cin>>grid[i];
    }
    visited.assign(n,vector<bool>(m,false));
    int rooms=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (grid[i][j]=='.'&&!visited[i][j]) {
                bfs(i,j);
                rooms++;
            }
        }
    }

    cout<<rooms<<"\n";
    return 0;
}
