#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
ll GCDD(ll a, ll b) {
    if (b == 0)
        return a;
    return GCDD(b, a % b);
}
ll LCM(ll a, ll b) {
    if (a == 0|| b==0)
        return 0;
    return (a/GCDD(a, b))*b;
}
int main() {
ll a,b;cin>>a>>b;
cout<<GCDD(a,b)<<" "<<LCM(a,b)<<endl;
}