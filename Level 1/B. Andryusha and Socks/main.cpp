//link ; https://codeforces.com/group/3nQaj5GMG5/contest/372026/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define vii(v,n)for(int i=0;i<n;i++)cin>>v[i]
const int MAXN= 1e5+1;
int main() {
int n;cin>>n;
    n*=2;
    vector<int>v(n);
vii(v,n);
    bitset<MAXN>table;
    int cnt=0;
    int maxCount=0;
    for(int i=0;i<n;i++) {
        if (!table[v[i]]) {
            table[v[i]]=true;
            cnt++;
            maxCount=max(maxCount,cnt);
        }else {
            table[v[i]]=false;
            cnt--;
        }
    }
cout<<maxCount<<ln;
}