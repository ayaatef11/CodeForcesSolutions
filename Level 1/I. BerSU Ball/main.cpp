//skill : https://codeforces.com/group/T3p02rhrmb/contest/343965/problem/I

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
int main() {
    int n;cin>>n;
    vector<int> b(n);
    for (int i=0;i<n;i++)cin>>b[i];

    int m;cin>>m;
    vector<int> g(m);
    for (int i=0;i<m;i++)cin>>g[i];
    sort(b.begin(),b.end());
    sort(g.begin(),g.end());
    // 1 2 4 6
     //1 5 6 7 9
    int i=0,j=0;
    int cnt=0;
    while (i<n && j<m) {
        int diff=abs(b[i]-g[j]);
        if (diff<=1) {
            cnt++;
            i++,j++;
        }
        else if (b[i]<g[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    cout<<cnt;
}