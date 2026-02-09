#include <bits/stdc++.h>
using namespace std;
vector<int>a;
int solve(int i,int num) {
    if(i==a.size()) {
        if (num>0)return 1;
        return 0;
    }
    bool isEven=(a[i]%2)==0;
    return solve(i+1,isEven?num+1:num-1)+solve(i+1,num);
}
int main() {
int n;cin>>n;
    a.assign(n,0);
    for (int i=0;i<n;i++)cin>>a[i];
cout<<solve(0,0);
}