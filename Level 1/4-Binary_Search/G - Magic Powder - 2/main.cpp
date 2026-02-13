#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, k;cin>>n>>k;
    ll a[n],b[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<n;i++)cin>>b[i];
    ll start=0, end=2e9;
    ll res=0;
    while (start<=end) {
        ll mid=(start+end)/2;
        // if (b[n-1]+k<mid)end=mid;
        ll need=0;
        //now use mid as the selected powder amount
        for (ll i=0;i<n;i++) {
            ll req=a[i]*mid;
            if (req>b[i]) need+=(req-b[i]);
            if (need>k)break;
        }
        if (need<=k) {
            res=max(res,mid);
            start=mid+1;
        }else end=mid-1;

    }
    cout<<res<<endl;
}