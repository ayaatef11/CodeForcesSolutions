#include <bits/stdc++.h>
using namespace std;
int n;
int m;
vector<vector<char>> v;
int entranceRow,entranceCol;
vector<int>visited;
vector<vector<char>> directions={{1,0},{-1,0},{0,1},{0,-1}};
void BFS(int node) {
   int start= v[entranceRow][entranceCol] ;
queue<int>q;
   q.push(start);
   v[entranceRow][entranceCol]=node;
   q.push(start);
   int steps=0;
   while(!q.empty()) {


   }
}
int main() {
v.resize(n,vector<char>(m,'.'));


}