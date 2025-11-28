#include <bits/stdc++.h>
using namespace std;
int main() {
int n,m;cin>>n>>m;
queue<tuple<int,int,int,set<char>>>q;
vector<int>dr={0,0,-1,1};
vector<int>dc={-1,1,0,0};
int allKeys=0;
set<tuple<int,int,set<char>>> visited;
vector<vector<char>>matrix(n,vector<char>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (matrix[i][j]=='@') {
q.push({i,j,0,{}});
            }
            else if (islower(matrix[i][j])) {
                allKeys=max(allKeys,matrix[i][j]-'a'+1);
            }
        }
    }

    while (!q.empty()) {
       auto[r,c,steps,keys]=q.front();q.pop();
        if ((int)keys.size()==allKeys) {
            cout<<steps;
            return 0;
        }
        for (int i=0;i<4;i++) {
            int row=r+dr[i];
            int col=c+dc[i];
            if (row>=0&&row<n&&col>=0&&col<m&&matrix[row][col]!='#') {
                char ch=matrix[row][col];

                auto tempSet=keys;
                if (islower(ch)) {
                    tempSet.insert(ch);
                }
                else if (isupper(ch) && !tempSet.count(tolower(ch)))
                    continue;

                auto state = make_tuple(row, col, tempSet);
                if (visited.count(state)) continue;
                visited.insert(state);
                q.push({row,col,steps+1,tempSet});

            }
        }
    }
    cout<<-1;
}