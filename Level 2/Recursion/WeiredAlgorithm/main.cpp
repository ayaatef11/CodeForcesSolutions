#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(ll n) {
    cout<<n<<" ";
    if (n==1)return ;
    if (n%2==0)
        solve(n/2);
    else
        solve(n*3+1);
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
ll x;cin>>x;
    solve(x);

}