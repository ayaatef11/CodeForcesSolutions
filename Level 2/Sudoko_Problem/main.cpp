#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<vector<char>> &board, int row, int col,char c) {
    for (int i=0;i<9;i++) {
        if (board[row][i]==c || board[i][col]==c) {return false;}
        if (board[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;//check if it is in the same square or not
    }
    return true;
}
//any digit should not appear twice in a row or colum or square 3*3
bool solve(vector<vector<char>>&broad) {
for (int i=0; i<broad.size(); i++) {
    for (int j=0; j<broad[0].size(); j++) {
        if (broad[i][j] == '.') {
            for (char c ='1';c<='9';c++) {
                if (isValid(broad,i,j,c)) {
                    broad[i][j] = c;
                    if (solve(broad)) return true;
                     broad[i][j]='.';
                }
            }
            return false;
        }
    }
}
  return true;
}
int main() {


}