//link : https://codeforces.com/group/T3p02rhrmb/contest/343965/problem/F
#include <bits/stdc++.h>
#define ll long long
#define ln '\n'
using namespace std;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main() {
int n;cin>>n;
    set<int> a;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
a.insert(x);
    }
int n2 = a.size();
    cout<<(1LL*n2*(n2+1)/2)-(n-n2);
}