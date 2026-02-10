#include <bits/stdc++.h>
using namespace std;
vector<long long>a;
long long  diff(int i,long long sum1,long long sum2) {
    if (i>=a.size())return abs(sum1-sum2);
    long long  res1= diff(i+1,sum1+a[i],sum2);
    long long res2=diff(i+1,sum1,sum2+a[i]);
    return min(res1,res2);
}
int main() {
int n;cin>>n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    cout<<diff(0,0,0)<<endl;
}