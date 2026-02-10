#include <bits/stdc++.h>
using namespace std;
const long long MAXN=1e6;
long long n;
unordered_map<long long,long long> dp;
long long bytelandian(long long f) {
 if (f==0) return 0;
 if (dp.count(f))return max(f,dp[f]);
dp[f]=bytelandian(f/2)+bytelandian(f/3)+bytelandian(f/4);
 return max(f,dp[f]);
}
int main() {
cin>>n;
 cout<<bytelandian(n)<<endl;
}