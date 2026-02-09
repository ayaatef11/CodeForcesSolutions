#include <bits/stdc++.h>
using namespace std;
int totalMoves;
int miniMoves=INT_MAX;
void solve(int l,int r,char c,string&s) {
    if (l==r) {
        if (s[l]!=c)totalMoves++;
        miniMoves=min(miniMoves,totalMoves);
        return ;
    }
    int mid=l+(r-l)/2;
    int leftMoves=0;
    int savedMoves=totalMoves;
    for (int i=l;i<=mid;i++) {
        if (s[i]!=c)leftMoves++;
    }
    totalMoves+=leftMoves;
    solve(mid+1,r,c+1,s);
    totalMoves=savedMoves;
    int rightMoves=0;
    for (int i=mid+1;i<=r;i++) {
        if (s[i]!=c)rightMoves++;
    }
    totalMoves+=rightMoves;
    solve(l,mid,c+1,s);
}
int main() {
int t;cin>>t;
    while (t--) {
        int x;cin>>x;
        string s;cin>>s;
        int n=s.length();
    totalMoves=0;
        miniMoves=INT_MAX;
        solve(0,n-1,'a',s);
        cout<<miniMoves<<endl;
    }
}