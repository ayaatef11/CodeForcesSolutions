#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+4;
const int MOD=1e9+7;
/*
 *you have an array of elements
 *and given mod
 *then there must be at least and index that should carry two elements
*/

ll sub(ll a ,ll b) {
    //why to add MOD again? becuase the answer may be negative so this is the reason
    return (((a%MOD)-(b%MOD))+MOD)%MOD;
}
int fast_power(int b,int e) {
    if (e==0)return 1;
int res=fast_power(b,e/2);
    res=(res*res)%MOD;
    if (e &1)res=(res*b)%MOD;
    return res;
}
int fast_power_iterative(int b,int e) {
    int res=1;
    while (e>0) {
        if (res & 1)res*=b;
        e>>=1;//you split it by two
        b=b*b;
    }
    return res%MOD;
}
bitset<N>is_prime;
void sieve() {//o(n log log n)
    is_prime.set();
    is_prime[0]=is_prime[1]=false;
    for (int i=2;i<N;i++) {
        if (is_prime[i]) {
            for (int j=i*j; j<N; j+=i) {
                is_prime[j]=false;
            }
        }
    }
}
vector<pair<int,int>>get_prime_factors(int n) {//o(sqrt n)
    vector<pair<int,int>>res;
    for (int i=2;i<=n/i;i++) {
        if (n%i)continue;
        int cnt=0;
        while (!(n%i)) {
            +cnt,n/=i;
        }
        res.emplace_back(i,cnt);
    }
    if (n>1) res.emplace_back(n,1);
    return res;
}
bool is_it_prime(int x) {
    for (int i=2;i<=x/i;++i) {
        if (!(x%i))return false;
    }
    return x>1;
}

vector<int>get_divisors(int n) {//o(sqrt n)
    vector<int>res;
    for (int i=1;i<=n/i;i++) {
        if (n%i==0) {
            res.push_back(i);
            if (i !=n/i)res.push_back(n/i);
        }
    }
    return res;
}
ll GCD(ll a,ll b) {//complexity is o(a)
    if (a<b)swap(a,b);
    if (b==0)return a;
    return GCD(a-b,b);
}
ll GCD_OPT(ll a,ll b) {//complexity is o(log b+a )
    if (a<b)swap(a,b);
    if (b==0)return a;
    return GCD_OPT(a%b,b);//the result should be between 0 and b-1
    //or we can say it is from 0 to a/2 -1
}
ll LCM(ll a,ll b) {
    if (a<b)swap(a,b);
    // return a*b/GCD(a,b);//this can cause overflow
    return a/GCD(a,b)*b;
}
//you can use built in functions
//__gcd and lcm

//mod inverse must work with prime mod
int d[10000];
void count_divisors(int n) {
    for (int i=1;i<n;i++) {
        for (int j=i;j<n;j+=i)d[j]++;
    }
}

void gen_divisors_rec(int idx,int cur,const vector<pair<int,int>>& fac,  vector<ll>& out) {
    if (idx == (int)fac.size()) {
        out.push_back(cur);
        return;
    }
    ll p=fac[idx].first;
    int e=fac[idx].second;
    ll val=1;
    for (int k=0;k<=e;++k) {
        gen_divisors_rec(idx+1,cur*val,fac,out);
        val*=p;
    }
}
vector<ll> get_all_divisors(int n) {
    vector<pair<int,int>> fac=get_prime_factors(n);
    vector<ll>divisors;
    gen_divisors_rec(0,1,fac,divisors);
    sort(divisors.begin(),divisors.end());
    return divisors;
}

int main() {

}