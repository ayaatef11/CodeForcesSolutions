#include<bits/stdc++.h>
#define ll long long
#define ln '\n'
using namespace std;
const int MAXN=1e6+1;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int>primes;
void sieve() {
    vector<int>arr(MAXN,1);
    arr[0]=arr[1]=0;
    for (int i=2;i<MAXN/i;i++) {
        if (arr[i]) {
            for (int j=i*i;j<MAXN;j+=i) {
                arr[j]=0;
            }
        }
    }
    for (int i=0;i<arr.size();i++) {
        if (arr[i])primes.push_back(i);
    }
}
int main() {
//>=lower bound
fast();
    sieve();
    int n,m;cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            int x=lower_bound(primes.begin(),primes.end(),arr[i][j])-primes.begin();
            arr[i][j]=primes[x]-arr[i][j];
        }
    }
int ans=MAXN;
    for (int i=0;i<n;i++) {
        int rowSum=0;
        for (int j=0;j<m;j++) {
rowSum+=arr[i][j];
        }
        ans=min(ans,rowSum);
    }
    for (int i=0;i<m;i++) {//dont forget to swap m and n-->important
        int ColSum=0;
        for (int j=0;j<n;j++) {
            ColSum+=arr[j][i];
        }
        ans=min(ans,ColSum);
    }
    cout<<ans<<ln;
}