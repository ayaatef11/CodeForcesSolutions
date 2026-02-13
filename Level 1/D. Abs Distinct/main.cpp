//link: https://codeforces.com/group/T3p02rhrmb/contest/343965/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

int main() {
int n;cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin>>v[i];
    int cnt=0;
for (int i=0;i<n;i++) {
    cnt++;
    for (int j=i+1;j<n;j++) {
        if (abs(v[i])==abs(v[j])){
            cnt--;
            break;
        }
    }
}
    cout<<cnt;
}