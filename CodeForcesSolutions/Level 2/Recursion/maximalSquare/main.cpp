#include <bits/stdc++.h>
using namespace  std;
int maximalSquare(vector<vector<char>>matrix) {
 int rows = matrix.size(), cols = matrix[0].size();
 int maxSize=0;
vector<vector<int>> dp(rows,vector<int>(cols,0));
for (int i=0;i<rows;i++) {
 for (int j=0;j<cols;j++) {
  if (matrix[i][j] == '1') {
   if (i==0||j==0)dp[i][j]=1;
   else {
    dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
   }
   maxSize=max(maxSize,dp[i][j]);

  }
 }

}
 return maxSize*maxSize;
}
int solve(int row, int col,vector<vector<char>>matrix) {
 int rows = matrix.size(), cols = matrix[0].size();
 int maxSize=0;
 vector<vector<int>> dp(rows,vector<int>(cols,0));
 if (matrix[row][col] == '1') {
  if (row==0||col==0)dp[row][col]=1;
  else {
   dp[row][col]=1+min({dp[row][col-1],dp[row-1][col],dp[row-1][col-1]});
  }
  maxSize=max(maxSize,dp[row][col]);

 }
 solve(row,col+1,matrix);
solve(row+1,col,matrix);
 return maxSize*maxSize;
}

 int main() {
 vector<vector<char>> matrix={{'0','1'},{'1','0'}};
cout<<maximalSquare(matrix)<<endl;
}