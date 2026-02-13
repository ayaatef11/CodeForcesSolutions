#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n, k;cin>>n>>k;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int start=0, end=1e6;
    int res=0;
    while (start<=end) {
        int mid=(start+end)/2;
        if (b[n-1]+k<mid)end=mid;
        int need=0;
        //now use mid as the selected powder amount
        for (int i=0;i<n;i++) {
            int req=a[i]*mid;
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