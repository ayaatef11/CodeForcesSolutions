#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int MAXN=1e9+5;
int n,m,q;
    vector<vector<ll>>rightDiagonal;
vector<vector<ll>>leftDiagonal;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
void preprocess() {
    int l,x,y,k,a;
    cin>>l>>x>>y>>k>>a;
x--,y--;
    if(l==1) {
        //optimization with prefix sum
        int endX=min(n-1,x+k-1);
        int endY=min(m-1,y+k-1);
        rightDiagonal[x][y]+=a;
        if(endX+1<n&&endY+1<m)
            rightDiagonal[endX+1][endY+1]-= a;
        //time limit in this part
        // for (int i=0;i<k && (x+i)<n &&(y+i<m);i++) {
        //     v[x+i][y+i]+=a;
        // }
    }
    else if (l==2) {
        int endX=min(n-1,x+k-1);
        int endY=max(0,y-k+1);
        leftDiagonal[x][y]+=a;
        if(endX+1<n&&endY-1>=0)
            leftDiagonal[endX+1][endY-1] -= a;
        // for (int i=0;i<k && (x+i)<n &&(y-i>=0);i++) {
            //     v[x+i][y-i]+=a;
            // }
        }
    }

int main() {
    fast();
cin>>n>>m>>q;
    rightDiagonal.assign(n+2,vector<ll>(m+2,0));
    leftDiagonal.assign(n+2,vector<ll>(m+2,0));

    while ( q--) {
        preprocess();//here we preprocess
    }
    //prefix sum for right diagonal
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
          if (i>0&&j>0)  rightDiagonal[i][j]+=rightDiagonal[i-1][j-1];
        }
    }
    //prefix sum for left diagonal
    for (int i=0;i<n;i++) {
        for (int j=m-1;j>=0;j--) {
            if (i>0&&j<m-1)  leftDiagonal[i][j]+=leftDiagonal[i-1][j+1];
        }
    }

for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
        cout<<(rightDiagonal[i][j]+leftDiagonal[i][j]);
        if (j<m)cout<<" ";
    }
    cout<<ln;
}

}