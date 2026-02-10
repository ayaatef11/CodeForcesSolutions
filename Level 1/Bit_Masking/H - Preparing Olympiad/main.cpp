#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int oo= 1e9;
#define ln '\n'
int main() {
int n,l,r,x;cin>>n>>l>>r>>x;
    vector<int> a(n);
for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    for (int mask=0; mask<(1<<n);mask++) {
ll sum=0;
        int mini=oo,maxi=-oo,cnt=0;
        for (int i=0;i<n;i++) {
            if (mask&(1<<i)) {//if mask is 3 meaning 101 then we need to take first and third elemnt and hot to check the bit , we and it with 1
                sum+=a[i];
                mini=min(mini,a[i]);
                maxi=max(maxi,a[i]);
                cnt++;
            }
        }
        if (cnt>=2 && sum>=l && sum<=r && maxi-mini>=x) ans++;
    }
    cout<<ans<<ln;
}