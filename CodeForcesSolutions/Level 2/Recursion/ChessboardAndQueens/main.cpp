#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> board;
int solutions;
vector<bool>cols(8,0);
vector<bool>dig1(15,0);
vector<bool>dig2(15,0);
void solve(int row) {
    if (row==8) {
        solutions+=1;
        return;
    }
    for (int col=0;col<8 ; col++) {
if (board[row][col]=='.'&& !cols[col]&&!dig1[row+col]&&!dig2[row-col+7]) {
cols[col]=1;
    dig1[row+col]=1;
    dig2[row-col+7]=1;
    solve(row+1);
    //backtrack
    cols[col]=false;
    dig1[row+col]=false;
    dig2[row-col+7]=false;
}
    }

}
int main() {
    board.resize(8, vector<char>(8));

for (int i=0;i<8;i++) {
    for (int j=0;j<8;j++) {
        cin >> board[i][j];
    }
}
      solve(0) ;
    cout<<solutions<<endl;
}