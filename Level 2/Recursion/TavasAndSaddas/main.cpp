#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt=0;
ll solve(ll n,ll target) {
    if (n >target) return 0;
    if (n!=0) {
        cnt++;
        if (n==target)return cnt;
    }
     ll res= solve(n*10+4 ,target);
if (res!=0) return res;
   res= solve(n*10+7,target);
    if (res!=0) return res;
    return 0;
}
int  main() {
ll n;cin>>n;
    cout<<solve(0,n)<<endl;
}