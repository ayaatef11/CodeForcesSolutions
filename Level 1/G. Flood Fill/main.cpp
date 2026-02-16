//link: https://codeforces.com/group/gA8A93jony/contest/269931/problem/G
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,x,y;

vector<vector<char>> v;
vector<vector<char>>visited;
int solve(int i,int j) {
   if (i>=n ||i<0 || j>=m || j<0) return 0;
   if (v[i][j]=='*')return 0;

   if (!visited[i][j]) {
      visited[i][j]=true;
   }
   else return 0;
   int ch1=solve(i+1,j);
   int ch2=solve(i-1,j);
   int ch3=solve(i,j+1);
   int ch4=solve(i,j-1);
   return ch1+ch2+ch3+ch4+1;
}
int main() {
cin>>n>>m;
   v.assign(n,vector<char>(m));
   for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
         cin>>v[i][j];
      }
   }
   cin>>x>>y;
   visited.assign(n,vector<char>(m));
   cout<<solve(x-1,y-1)<<endl;
}