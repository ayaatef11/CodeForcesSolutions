#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, m;cin>>n>>m;
    ll arr[n];
    for(ll i=0;i<n;i++)cin>>arr[i];
    ll start=0, end=1e18;
    ll t=0;

    while (start<=end) {
        ll mid=(start+end)/2;
        __int128 sum=0;//for overflow
        for (ll i=0;i<n;i++) {
            sum+=(mid/arr[i]);
            if (sum >= m) break;
        }
        if (sum>=m) {
            end=mid-1;
            t=mid;
        }else start=mid+1;
    }
    cout<<t<<endl;
}