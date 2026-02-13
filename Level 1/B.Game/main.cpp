//link : https://codeforces.com/group/T3p02rhrmb/contest/343396/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
int main() {
int n,t;;cin>>n>>t;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    while (t--) {
        int k;cin>>k;
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if (a[mid]>k) {
                ans=a[mid];
                high=mid-1;
            }else {
                low=mid+1;
            }
        }
        cout<<ans<<ln;
    }
}