#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> board;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col]=='Q') return false;
        if (col-(row-i)>=0&&board[i][col-(row-i)]=='Q') return false;
        if (col+(row-i)<n&&board[i][col+(row-i)]=='Q') return false;
    }
    return true;
}

void solve(int row) {
    if (row == n) {
        for (auto &s : board) cout<<s<< "\n";
        cout << "\n";
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 'Q';
            solve(row+1);
            board[row][col] = '.';
        }
    }
}

int main() {
    cin >> n;
    board.assign(n, string(n, '.'));
    solve(0);
    return 0;
}
