#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+4;
const int MOD=1e9+7;
const int MAXN=1e6;
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
        e>>=1;
        b=b*b;
    }
    return res%MOD;
}
bitset<N>is_prime;//faster and less memory
void sieve() {//o(n log log n)
    is_prime.set();//set to 1
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
    vector<pair<int,int>>res;//use pair as index 0 will be the number and 1 will be its power
    for (int i=2;i<=n/i;i++) {
        if (n%i)continue;
        int cnt=0;
        while (!(n%i)) {
            +cnt,n/=i;
        }
        res.emplace_back(i,cnt);
    }
    if (n>1) res.emplace_back(n,1);//so important , to check theat no number yet
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
        if (!(n%i)) {
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

// دالة الخوارزمية الإقليدية الموسعة
// تحسب gcd(a,b) وتجد x,y بحيث a*x + b*y = gcd(a,b)
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
    if (a < 0) {
        ll r=extended_euclid(-a,b,x,y);
        x*=-1;
        return r;
    }
    if (b<0) {
        ll r=extended_euclid(a,-b,x,y);
        y*=-1;
        return r;
    }

    if (b==0) {
        x=1,y=0;
        return a;
    }
    ll g=extended_euclid(b,a%b,y,x);
    y-=(a/b)*x;
    return g;
}

// دالة حل معادلة ديوفانتين الخطية
// تحل المعادلة: a*x + b*y = c
ll ldioph(ll a, ll b, ll c, ll &x, ll &y, ll &found) {
    ll g = extended_euclid(a, b, x, y);

    // التحقق من وجود حل
    // الحل موجود فقط إذا كان c قابل للقسمة على gcd(a,b)
    if ((found=(c%g==0))) {
        x*=c/g;
        y*= c/g;
    }
    return g;
}

// دالة مساعدة لطباعة النتائج
void solve_equation(ll a, ll b, ll c) {
    ll x, y, found;
    ll g = ldioph(a, b, c, x, y, found);

    cout << "المعادلة: " << a << "*x + " << b << "*y = " << c << endl;

    if (found) {
        cout << "الحل موجود!" << endl;
        cout << "gcd(" << a << ", " << b << ") = " << g << endl;
        cout << "حل خاص: x = " << x << ", y = " << y << endl;

        // التحقق من الحل
        cout << "التحقق: " << a << "*" << x << " + " << b << "*" << y
             << " = " << (a*x + b*y) << endl;

        // الحل العام
        cout << "\nالحل العام:" << endl;
        cout << "x = " << x << " + " << (b/g) << "*t" << endl;
        cout << "y = " << y << " - " << (a/g) << "*t" << endl;
        cout << "حيث t أي عدد صحيح" << endl;
    } else {
        cout << "لا يوجد حل!" << endl;
        cout << "السبب: " << c << " غير قابل للقسمة على gcd("
             << a << ", " << b << ") = " << g << endl;
    }
    cout << "------------------------" << endl;
}

void getNumberOfDivisorsForNPowerM() {
    int pr[MAXN]; // pr[i] stores smallest prime factor of i

    // Sieve to precompute smallest prime factor for each number
    void sieve() {
        for (int i = 2; i < MAXN; i++) {
            if (pr[i] == 0) { // i is prime
                for (int j = i; j < MAXN; j += i) {
                    if (pr[j] == 0) {
                        pr[j] = i;
                    }
                }
            }
        }
    }
    int n, m;
    cin >> n >> m;

    map<int, int> frq;
    while (n != 1) {
        frq[pr[n]]++;
        n /= pr[n];
    }

    int answer = 1;
    for (auto [p : const long long , cnt : long long ]: frq) { // key
        answer = (answer * (cnt * m % MOD + 1)) % MOD;
    }
    cout << answer << "\n";
}
void segemetedSieveNoPreGen(long long l,long long r){
    for(long long i=2;i*i<=r;i++){
        for(long long j=max(i*i,(l+i-1)/i*i);j<=r;j+=i){
            {
                composite[j-l]=true;
            }
        }

    }
    if(l==1)composite[0]=true;
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

void getModForVeryVeryLargeNumber() {
    string n;int z;
    cin>>n>>z;
    int last=0;
    for (int i=0;i<n.length();i++) {
        last=(last*10+(n[i]-'0'))%z;
    }
    if (last==0)cout<<"yes n divisable by z";
    else cout<<"no";
}
int getLonGestSubarrayDivisableBy_k() {
    int n,k;cin>>n>>k;
    vector<int>a(n+1);//for prefix;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]+=a[i-1];
        a[i]%=k;
    }
    // vector<vector<int>>idx(k);
    // for (int i=0;i<k;i++) idx[a[i]].push_back(i);
    // int answer=0;
    // for (int i=0;i<k;i++) {
    //     if (idx[i].empty())continue;
    //     answer=max(answer,idx[i].back()-idx[i].front());
    // }
    //optimized way
    int answer=0;
    vector<int>first_idx(k);
    for (int i=1;i<=n;i++) {
        if (first_idx[a[i]]==0)first_idx[a[i]]=i;//if it is the first appearence
        answer=max(answer,i- first_idx[a[i]]);//to get the distance
    }
    return answer;
}
int main() {

}