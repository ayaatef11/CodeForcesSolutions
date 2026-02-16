//link https://codeforces.com/group/gA8A93jony/contest/269931/problem/G
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> mat1;
vector<vector<int>> mat2;
vector<vector<ll>> mat3;
int n1,c1,n2,c2;

vector<vector<ll>> multiply() {
    for (int i=0;i<n1;i++) {
        for (int j=0;j<n2;j++) {
            for (int k=0;k<c1;k++) {
                mat3[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    return mat3;
}
void multiply_recursive(int i,int j,int k) {
    if (i>=n1) return;
    if (j>=n2) {
        multiply_recursive(i+1,0,0);
        return ;
    }
    if (k>=c1){
        multiply_recursive(i,j+1,0);
        return;
    }
    mat3[i][j]+=mat1[i][k]*mat2[k][j];
    multiply_recursive(i,j,k+1);

}
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
int main() {
    fast();
    cin>>n1>>c1;

  mat1.assign(n1,vector<int>(c1));
    for (int i=0;i<n1;i++) {
        for (int j=0;j<c1;j++) {
            cin>>mat1[i][j];
        }
    }
    cin>>n2>>c2;
    mat2.assign(n2,vector<int>(c2));
    for (int i=0;i<n2;i++) {
        for (int j=0;j<c2;j++) {
            cin>>mat2[i][j];
        }
    }
    mat3.assign(n1,vector<ll>(c2));
    multiply_recursive(0,0,0);
    for (int i=0;i<mat3.size();i++) {
        for (int j=0;j<mat3[0].size();j++) {
            cout<<mat3[i][j]<<" ";
        }
        cout<<endl;
    }
}