//link https://codeforces.com/group/T3p02rhrmb/contest/343396/problem/T
#include <bits/stdc++.h>
using namespace std;
#define ll long long
double solve(double x) {
    double l=0,r=x,ans=0;
    double EPS=1e-9;
    while (r-l > EPS) {
        double mid=l+(r-l)/2;
        if (mid <=x/mid) {
            ans=mid;
            l=mid+EPS;
        }
        else r=mid;
    }
    return ans;
}
int main() {
double n;cin>>n;
    cout<<fixed<<setprecision(9)<<solve(n)<<'\n';

}