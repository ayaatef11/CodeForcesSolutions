#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> board(8, vector<char>(8, '.'));
vector<int> positions(8);

bool isValid(int row, int col) {
    for (int i = 0; i < 8; i++) {
        if (i!=row&&board[i][col]=='q') return false;
        if (abs(positions[i] - row) == abs(i - col)) return false;
    }

    return true;
}

int minMoves;

void solve(int col,int moves) {
    if (col==8) {
        minMoves = min(minMoves, moves);
        return;
    }

    for (int row=0;row<8;row++){
        if (board[row][col]=='q'&& !isValid(row, col)) {
            board[row][col] = '.';
            solve(col+1,moves+1);
            board[row][col] = 'q';
        }
        }
    }


int main() {
    int t = 1;
    while(cin >> positions[0]) {
        for (int i=1;i<8;i++) {
            cin>>positions[i];
            positions[i]--;
        }

        for (int i=0;i<8;i++)
            for (int j =0;j<8;j++)  board[i][j] = '.';

        minMoves = 8;
        solve(0, 0);
        cout <<"Case " <<t<<": "<<minMoves-1<<"\n";
        t++;
    }
}
