//link https://codeforces.com/group/T3p02rhrmb/contest/343396/problem/M
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

int main() {
int t;cin>>t;
    while(t--) {
        int n,k;cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
     auto can=[&](int num,int ki) {
         int start=a[0];
         for (int i=1;i<n;i++) {
             if (a[i]-start+1>num) {
                 ki--;
                 start=a[i];
             }

             if (!ki && i<n)return false;
         }
         return true;
     };
        ll l=1,r=1e9;
        ll ans=0;
        while (l<=r) {
            ll m=(l+r)/2;

            if (can(m,k)) {
                r=m-1;
                ans=m;
            }
            else l=m+1;
        }
        cout<<ans<<ln;
    }


}