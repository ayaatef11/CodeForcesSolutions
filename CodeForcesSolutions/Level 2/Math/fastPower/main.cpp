#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll n, m;
int solve(ll n,ll m) {
    if (m==0)return 1;
  ll half=  solve(n,m/2);
    ll res= (half*half)%MOD;
    if (m%2==1)res=(res*n)%MOD;
    return res;
}
int main() {
cin>>n>>m;
cout<<solve(n%MOD,m);

}