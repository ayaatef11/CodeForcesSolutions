#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a;
int miniDiff=1e9;
void solve(size_t i,ll diff) {
    if (i>=a.size()) {
        if (abs(diff)<miniDiff) {miniDiff=abs(diff);}
        return ;
    }
    solve(i+1,diff+a[i]);//it may cause integar overflow so use long long instead of int
    solve(i+1,diff-a[i]);
}
int main() {
int n;cin>>n;
    a.assign(n,0);
    for(int i=0;i<n;i++)cin>>a[i];
    solve(0,0);
    cout<<miniDiff<<endl;
}