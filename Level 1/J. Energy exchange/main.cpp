#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
vector<double> a;
void solve(double& surplus,double& need,double mid, double k) {
    int n=(int)a.size();
    for (int i=0; i<n;i++) {
        if (a[i]>mid)surplus+=(a[i] - mid) * (1 - k/100);
        else need+=(mid - a[i]);
    }
}
int main() {
    int n;
    double k; cin>>n>>k;
    double maxi=0;
    a.assign(n,0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }

    double lo=0,hi=maxi;
    double EPS =1e-7;

    while (hi-lo> EPS) {
        double mid =lo+(hi-lo)/2;
        double surplus = 0,need=0;
       solve(surplus,need,mid,k);
        if (surplus >= need) lo = mid;
        else hi = mid;
    }

    cout<<fixed<<setprecision(9)<<lo<< ln;
    return 0;
}
