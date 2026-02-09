#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
bool isSorted(int l,int r) {
    for (int i=l;i<r;i++) {
        if (v[i]>v[i+1])return false;
    }
    return true;
}
int solve(int i,int j) {
    if (isSorted(i,j)||i==j)return j-i+1;
    int mid=i+(j-i)/2;
return max(solve(i,mid),solve(mid+1,j));
}
int main() {
cin>>n;
    v.resize(n);
for (int i = 0; i < n; i++)cin>>v[i];
cout<<solve(0,n-1);
}