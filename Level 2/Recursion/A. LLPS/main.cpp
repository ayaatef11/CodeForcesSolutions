#include <bits/stdc++.h>
using namespace std;
bool is_palindromic(string y) {
    if (y.length() < 2)return true;
    int n = y.length();
    for (int i = 0; i < n / 2; i++) {
        if (y[i]!=y[n-i-1]) return false;
    }
    return true;
}
string s;
string miniS;
void solve(int i,string y) {
    if (i>=s.length()) {
        if (is_palindromic(y) && y>miniS) miniS = y;
        return;
    }
    solve(i+1,y+string(1,s[i]));//take it
    solve(i+1,y);//leave it

}
int main() {
cin>>s;
solve(0,"");
    cout<<miniS;
}