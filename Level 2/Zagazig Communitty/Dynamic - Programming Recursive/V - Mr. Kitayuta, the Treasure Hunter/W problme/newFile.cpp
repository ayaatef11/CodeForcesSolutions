#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,d;
vector<int>a;
int solve(int pos,int lastJumb) {
    if (pos>30000)return 0;
    //we have three choices either l or l+1 or l-1
    int ans=0;
    ans=max( ans,solve(pos+lastJumb,lastJumb));
    if (lastJumb-1>0) ans=max( ans,solve(pos+lastJumb-1,lastJumb-1));

    ans=max( ans,solve(pos+lastJumb+1,lastJumb+1));

    return a[pos]+ans;
}
int main() {
    cin>>n>>d;
    a.assign(30001,0);
    for(int i=0;i<n;i++) {
        int x;cin >>x;
        a[x]++;
    }

    cout<<solve(d,d)<<endl;
}