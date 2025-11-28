#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int sum(int n) {
    if (n == 0)return v[0];
    return v[n] + sum(n - 1);
}
int main() {
int t;cin>>t;
    int y=t;
    while (t--) {
        int x;cin>>x;
        v.resize(x);
        for (int i=0;i<x;i++) {
            cin>>v[i];
        }
        cout<<"Case "<<y-t<<": "<<sum(x-1)<<endl;
    }
}