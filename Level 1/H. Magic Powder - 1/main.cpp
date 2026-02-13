//link: https://codeforces.com/group/T3p02rhrmb/contest/343396/problem/H
#include <bits/stdc++.h>
#define ln '\n'
using namespace std;
#define ll long long
const int MAXN = 1e5;

bool can(int num,vector<int>a,vector<int>b,int k) {
    for (int i=0;i<(int )a.size();i++) {
        //use this way because it may casue overflow
        if ((b[i]/num<a[i])&& ((b[i]+k)/num<a[i]))return false;
        b[i]-=(num*a[i]);
        if (b[i]<0) {
            k+=b[i];
            b[i]=0;
        }
    }
        return true;
}
int main() {
    int n,k;

cin>>n>>k;
    vector<int>a;
    vector<int>b;
    a.assign(n,0);
    b.assign(n,0);
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) cin>>b[i];
    int low=1,high=MAXN,mid;///low is 1 as it will be passed as num in the function and it can cause runtime error
    int ans = 0;
    while (low<=high) {
        mid=low+(high-low)/2;
        if (can(mid,a,b,k)) {
            ans=mid;
            low=mid+1;
        }else {
            high=mid-1;
        }
    }
cout<<ans<<ln;
}