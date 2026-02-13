#include<bits/stdc++.h>
#define ll long long
#define ln '\n'
using namespace std;
const int MAXN=1e3+1;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int n;
vector<int>primes(MAXN,1);

void sieve() {
    primes[0]=primes[1]=0;
    for(int i=2;i<MAXN/i;i++) {
        if(primes[i]==1) {
            for(int j=i*i; j<MAXN; j+=i) {
                primes[j]=0;
            }
        }
    }
}



int main() {
fast();
    cin>>n;
vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<bool>ans(MAXN,0);
 for (int i=0;i<n;i++) {
     for(int j=i+1;j<n;j++) {
         int x = v[i]+v[j];
         if (primes[x]) {
             ans[i]=true;
             ans[j]=true;
         }else {
             ans[i]=false;
             break;
         }
     }
 }

    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<n;j++) {
            if(i&(1<<j)) {

            }
        }
        cout<<ln;
    }
}