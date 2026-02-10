#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7,n=1e5+5;
#define ll long long
//precompute fatorial
ll factorial[n];
ll inverse[n];

ll power(ll b,ll p) {
    ll res=1;
    while(p) {
        if(p&1)res=res*b%MOD;
        p>>=1,b=b*b%MOD;
    }
    return res%MOD;
}
ll inv(ll x ) {
    return power(x,MOD-2);
}
void precompute_factorial() {
    factorial[0]=factorial[1]=1;
    inverse[0]=inverse[1]=1;
    for (int i=2;i<n;i++) {
        factorial[i]=factorial[i-1]*i%MOD;
        inverse[i]=inv(factorial[i]);
    }
}
int ncr(int n,int r) {
    if (r>n)return 0;
    return factorial[n]*inverse[r] % MOD*inverse[n-r] %MOD;
}
int npr(int n,int r) {//now it is o(1)
    if (r>n)return 0;
    return factorial[n]*inverse[n-r] %MOD;//as not create the inverse for each eleemtn and this will take o(log n ) so  we can precompute it

}
//in questions ther eis a limit to the elements of the array
//but if it is not given , then you need to handle it manually to not cause overflow
//the concept of inclusion and exclusion
int generateSubsets(int n,vector<int>a,int x) {
    int res=0;
    for (int mask=1;mask<(1<<n);++mask) {
        int l=1,ones=0;
        for (int i=0;i<n;i++) {
            if (mask>>i & 1) {
                ones ^=1;
                // l=lcm(l,a[i]);
                int g=gcd(l,a[i]);
                l/=g;
                //handle overflow
              if (l>1e18/a[i]) {  // if (l*a[i]>1e18) { as it may also cause overflow
                   l=x+1;
                    break;
                }else {
                    l=l*a[i];

                }
            }
        }
        if (ones)res+=x/l;//odd
        else res-=x/l;
    }//if size of subset is odd then subtract else add
}
int main() {
string s;cin>>s;
vector<ll>freq(26);
    for (char i:s) {
        freq[i-'a']++;
    }
    precompute_factorial();
    ll res=factorial[s.size()];
    for (ll x:freq) {
        res=res *inv(factorial[x])%MOD;//=res/factorial[x]//no need to mod as the number gets smaller
        //but we can use the inverse of mod
    }
    cout<<res<<endl;//factorial of all the string (the full size)/factorial of repeated characters
}