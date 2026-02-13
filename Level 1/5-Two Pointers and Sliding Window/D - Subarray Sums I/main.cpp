#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
int main() {
    int n,m;cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int i=0,j=0;
    int sum=0;
    int cnt=0;
    while (i<n) {
        sum+=arr[i++];
        while (sum>m && j <= i) {
            sum-=arr[j++];
        }
        if (sum==m)cnt++;
    }
    cout<<cnt<<ln;
}