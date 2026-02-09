#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> v;
vector<vector<int>>prefix;
int a,b,c;
int getSum(int x1,int y1,int x2,int y2) {
    return prefix[x2][y2]-prefix[x1][y2]-prefix[x2][y1]+prefix[x1][y1];
}
int main() {
    ifstream fin("input.txt");
    fin>>n>>m;
    v.resize(n,vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            fin>>v[i][j];
        }
    }
fin>>a>>b>>c;
    prefix.resize(n+1,vector<int>(m+1,0));
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<m+1;j++) {
            prefix[i][j]=v[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    ofstream fout("output.txt");
int ans=0;
    // if (a+b+c!=prefix[n][m]) {
    //     fout<<ans;
    //     return 0;
    // }
    vector<int>temp2={a,b,c};
    sort(temp2.begin(),temp2.end());
    int sum1=0,sum2=0,sum3=0;
    //horizontal
for (int i=1;i<n-1;i++) {
    for (int j=i+1;j<n;j++) {
        sum1=getSum(0,0,i,m);
        sum2=getSum(i,0,j,m);
        sum3=getSum(j,0,n,m);
        vector <int> temp={sum1,sum2,sum3};
        sort(temp.begin(),temp.end());
        if (temp==temp2) {ans++;}
    }
}
    for (int i=1;i<m-1;i++) {
        for (int j=i+1;j<m;j++) {
            sum1=getSum(0,0,n,i);
            sum2=getSum(0,i,n,j);
            sum3=getSum(0,j,n,m);
            vector <int> temp={sum1,sum2,sum3};
            sort(temp.begin(),temp.end());
            if (temp==temp2) {ans++;}
        }
    }
    fout<<ans;
}