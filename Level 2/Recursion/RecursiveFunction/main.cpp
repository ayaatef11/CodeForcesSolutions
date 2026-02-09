#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(int n) {
    if (n==0)return 1;
    return n*solve(n-1);
}
int main() {
int x;cin>>x;
    cout<<solve(x);

}