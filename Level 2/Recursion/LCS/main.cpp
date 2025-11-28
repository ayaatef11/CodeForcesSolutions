#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s1,s2;
int n,m;
int total=0;
int maxi;
void solve(int i,int j) {
if (i==n||j==m) {
    maxi=max(maxi,total);
    return;
}
    if (s1[i]==s2[j]) {
        total++;
        solve(i+1,j+1);
        total--;
    }
    //take from s1 not take from s2
    solve(i+1,j);
    //not take from s1 take from s2
    solve(i,j+1);

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s1>>s2;
    n=s1.length();
    m=s2.length();
    solve(0,0);
    cout<<maxi<<" ";
}