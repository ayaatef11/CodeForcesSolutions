#include <bits/stdc++.h>
using namespace std;
int a,b;
vector<int>v;
bool solve(int n) {
    v.push_back(n);
    if (n==b)return true;
    if (n>b) {
        v.pop_back();
        return false;
    }
   if ( solve(n*2))return true;
    if (solve(10*n+1))return true;
    v.pop_back();
    return false;
}
int main() {

cin>>a>>b;
if (solve(a)) {
    cout<<"YES\n"<<v.size()<<'\n';
    for (int i=0;i<v.size();i++) {
        cout<<v[i]<<' ';
    }
    cout<<'\n';
}else {
    cout<<"NO\n";
}
}