//link : https://codeforces.com/group/T3p02rhrmb/contest/343396/problem/V
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e9;
#define ln '\n'

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int>x;
vector<int>v;

// double can(int point) {//this way is not monotonic, we need to search for min time
//     double t=0;
//     for (int i=0;i<x.size();i++) {
//         int dis=abs(x[i]-point);
//         double tim=(double)dis/v[i];
//         t=max(t,tim);
//     }
//     return t;
// }

bool can (double tim) {
    double left=-1e18;
    double right=1e18;
    for (int i=0;i<x.size();i++) {
        double dis=v[i]* tim;
        double r=x[i]+dis;
        double l =x[i]-dis;
        right=min(right,r);
        left=max(left,l);
    }
    return left<=right;
}

int main() {
int n;cin>>n;
    x.assign(n,0);
    v.assign(n,0);

    for(int i=0;i<n;i++) {
        cin>>x[i];
    }
for (int i=0;i<n;i++)cin>>v[i];
double EPS=1e-12;//number of iterations equal ot log(range/EPS) sso wehn tou minimize EPS you maximize number of iterations and also the time spent
    double l=0,r=1e9;
    double ans=0;
    for (int i=0;i<100;i++) {//optimization for the code as it gave me time limit when EPS was 1e-12 not 1e-6
        if (r-l>EPS) {
            double m=(double)l+(r-l)/2;
            if (can(m)) {
                r=m;
                ans=m;
            }else {
                l=m;
            }
        }
    }
cout<<fixed<<setprecision(12)<<ans<<ln;
}