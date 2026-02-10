#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>>v;
vector<int>w;
int weight=0;
int minCost = INT_MAX;

int n,m,x;
vector<int>res;
void solve(int i) {
    if (i==n) {
        for (int a=0;a<m;a++) {
            if (res[a]<x) return;
        }
        minCost=min(minCost,weight);
        return;
    }

    //take the row
    for (int j=0;j<m;j++) {
        res[j]+=v[i][j];
    }
    weight+=w[i];
    solve(i+1);
    //not take the row//backtrack
    for (int j=0;j<m;j++) {
        res[j]-=v[i][j];
    }
    weight-=w[i];
    solve(i+1);
}
int main() {
    cin>>n>>m>>x;
    v.resize(n,vector<int>(m));
    w.resize(n);
    res.assign(n,0);
    for (int i = 0; i < n; i++) {
        cin>>w[i];
        for (int j = 0; j < m; j++) {
            cin>>v[i][j];
        }
    }
    minCost = INT_MAX;
    solve(0);
    if(minCost == INT_MAX) cout << -1 << endl;
    else cout << minCost << endl;
}