#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
int n,k;
vector<int>arr;
void sieve() {
    for (int i=2;i<=n;i++) {
        for (int j=i*i;j<=n;j+=i) arr[j]=0;
    }
}
int main() {
cin>>n>>k;
    arr.assign(n+1,1);
    sieve();
    vector<int>primes;
    for (int i=2;i<=n;i++) {
        if (arr[i]) primes.push_back(i);
    }
    int sz=primes.size();
    int ans=0;
    for (int i=0;i<sz;i++) {
if (i==sz-1)break;
        int s=primes[i]+primes[i+1]+1;
        if (s>n)continue;
        else if (arr[s])ans++;
    }
    if (ans>=k)cout<<"YES"<<ln;
    else cout<<"NO"<<ln;
}