#include <bits/stdc++.h>
using namespace std;
vector<vector<char>>board(8,vector<char>(8,'.'));

bool isValid(int row,int col) {
    for (int i=0;i<row;i++)
        if (board[i][col]=='q' ) return false;

    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
        if(board[i][j]=='q')return false;

    for(int i=row-1,j=col+1;i>=0&&j<board.size();i--,j++)
        if(board[i][j]=='q') return false;

    return true;
}
int solve(int i,int j) {
    if (i==8)return 1;//all queens placed
    if (j==8)return 0;//row finished
    int ways=0;
    if (board[i][j]!='*' &&isValid(i,j)) {
        board[i][j]='q';
        ways+= solve(i+1,0);//move to next row and the column is 0
        board[i][j]='.';
    }
    ways+= solve(i,j+1);
    return ways;
}
int main() {
for(int i=0;i<8;i++) {
    for(int j=0;j<8;j++) {
        cin>>board[i][j];
    }
}
cout<<solve(0,0);
}