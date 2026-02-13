//link : https://codeforces.com/group/T3p02rhrmb/contest/343965/problem/J
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int MAXN = 1e9+1;
#define vii(v,n) for(int i=0;i<n;i++)cin>>v[i]
int main(){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
int n;cin>>n;
    vector<int>v(n);

int biggest=0,smallest=MAXN;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        biggest=max(biggest,v[i]);
        smallest=min(smallest,v[i]);
    }
ll sum=biggest+smallest;
    ll ans=0;
    sort(v.begin(),v.end());
    //1 2 4 5 6 8
    int i=0,j=n-1;
    while(i<j) {
        ll sumation=(ll)v[i]+(ll)v[j];
        if (sumation==sum) {
            ans++;
            i++;
            j--;
        }
        else if (sumation>sum)j--;
        else i++;
    }
    cout<<ans<<ln;
}