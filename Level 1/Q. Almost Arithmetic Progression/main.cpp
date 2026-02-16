//link : https://codeforces.com/group/3nQaj5GMG5/contest/372026/problem/Q
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int MAXN=1e9+1;
//we have nine possibilities
//if a is v[0] adn b is v[1]
//+ + , - - , + - , - +,0 +,0 -,- 0,+ 0, 0 0
int main() {
vector<vector<char>>possiliblities(9,vector<char>(2));
    possiliblities={
        {'+','+'},{'-','-'},{'+','-'},{'-','+'},{'0','+'},{'0','-'},{'-','0'},{'+','0'},{'0','0'}
    };
    int n;cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    if (n<=2) {
        cout<<'0';
        return 0;
    }
    int ans=MAXN;
for (int j=0;j<9;j++){
    ll a=v[0];
    ll b=v[1];
    int changes=0;
    if (possiliblities[j][0]=='-') {
        a--;
        changes++;
    }
    else if (possiliblities[j][0]=='+') {
        a++;
        changes++;
    }
    if (possiliblities[j][1]=='-') {
        b--;
        changes++;
    }
    else if (possiliblities[j][1]=='+') {
        b++;
        changes++;
    }
    ll diff=b-a;
    ll prev=b;
    bool ok=true;

    for (int i=2;i<n;i++) {
        ll expected=prev+diff;
        ll delta=expected-v[i];
        if (abs(delta)>1) {ok = false;break;}
        if (delta!=0)changes++;
        prev=expected;
    }

    if (ok)ans=min(ans, changes);
}

    if (ans==MAXN)cout <<-1;
    else cout<<ans;
}