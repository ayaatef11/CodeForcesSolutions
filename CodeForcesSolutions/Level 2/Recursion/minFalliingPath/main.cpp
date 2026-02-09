#include <bits/stdc++.h>
using namespace  std;

int result=0;
int solve(int row,int col,vector<vector<int>>& matrix) {
if (row==0 )return matrix[row][col];
 if (row<0||col < 0 || col >= matrix[0].size()) return 1e9;
 int sum=0,sum2=0,sum3=0;
  sum += matrix[row][col] + solve(row-1,col,matrix);
  sum2 += matrix[row][col] + solve(row-1,col-1,matrix);
  sum3 += matrix[row][col] + solve(row-1,col+1,matrix);
 return min(sum,min(sum2,sum3));
}
int minFallingPathSum(vector<vector<int>>& matrix) {
 int rows = matrix.size();
 int cols = matrix[0].size();
 int ans = 1e9;

 for (int col = 0; col < cols; col++) {
  ans = min(ans, solve(rows-1, col, matrix));
 }

 return ans;}

 int main() {
 vector<vector<int>> matrix={{2,1,3},{6,5,4},{7,8,9}};
cout<<minFallingPathSum(matrix);
}