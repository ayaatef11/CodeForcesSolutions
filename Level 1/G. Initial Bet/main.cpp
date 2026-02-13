//link  ; https://codeforces.com/group/T3p02rhrmb/contest/338802/problem/O
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main() {
fast();
    ll n,m;
    cin>>n>>m;

    if (n>=31) {
        cout<< m<<ln;
    } else {
        cout << m%(1LL<<n) << endl;
    }
}