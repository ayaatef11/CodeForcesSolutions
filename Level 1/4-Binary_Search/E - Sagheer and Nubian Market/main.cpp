#include <bits/stdc++.h>
using namespace std;
#define ll long long
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
int main() {
    fast();
    int n,s;cin>>n>>s;
    int arr[n];
    // vector<int> prefix(n+1,0);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        // prefix[i+1]=prefix[i]+arr[i]*i;
    }
    int k=0,t=0;
    int start =0,end=n;
    int sum=0;
    while(start<=end) {
        int mid = (start+end)/2;
        vector<ll> cost(n);
        for (int i=0;i<n;i++) {
            cost[i] = arr[i] + (ll)(i+1)*mid;
        }
        sort(cost.begin(), cost.end());
        ll sum = 0;
        for (int i=0;i<mid;i++) sum += cost[i];

        if (sum<=s) {
            k=mid;
            t=sum;
            start=mid+1;

        }else if (sum>s) {
            end=mid-1;
        }
        sum=0;
    }
    cout<<k<<" "<<t;
}