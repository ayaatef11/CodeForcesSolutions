#include <bits/stdc++.h>
using namespace std;
bool checkBit(int x,int pos) {
    return (x>>pos)&1;
}
int findMSB(int x){
   x |= x>>1;
   x |= x>>2;
   x |= x>>4;
   x |= x>>8;
   x |= x>>16;
   x = x+1;
   return(x >> 1);
}
//covert binary to integar -->   auto integer = 0b0110110;

int findsubsetXOR (int set[], int size){//i am not sure yet about it
    if (size == 1){
        return set[size - 1];
    }
    else
        return 0;
}
//chceck number is power of 2
int isPowerof2(int n){
    return n && (!(n&(n-1)));
}
// Direct XOR of all numbers from 1 to n

int findXORuptoN(int n){
    switch( n%4){
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        case 3: return 0;
        default: break;
    }
}
void MaximumAnd() {
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for (int &i : a) cin>>i;
    int ans=0;
    for (int bit=30; bit>=0; bit--) {
        int cost=0;
        for (int &x : a) {
            if (!checkBit(x,bit)) cost+=1;
        }
        if (cost<=k) {
            k-=cost;
            ans+=(1<<bit);
        }
    }
    cout<<ans<<endl;
}
void prefixXOR() {
    int n; cin >> n;
    vector<int> a(n + 1), pref(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << (pref[r] ^ pref[l - 1]) << endl;
    }
}
void PrefixAnd() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> pref(32, vector<int>(n));

    for (int bit=0;bit<32;++bit) {
        for (int j=1;j<=n;++j) {
            pref[bit][j]=pref[bit][j - 1]+(a[j]>>bit&1);
        }
    }

    int q; cin >> q;
    while (q--) {
        int l,r; cin>>l>>r;

        int ans=0;
        for (int bit=0;bit<32;++bit) {
            int countOnes=pref[bit][r] - pref[bit][l - 1];
            if (countOnes>0) ans+=(1<<bit);//ffor or , you check that one appear at least once
        }

        cout << ans << endl;
    }
}
void LVA_AND_PVA() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> pref(32, vector<int>(n + 1));

    for (int bit = 0; bit < 32; ++bit) {
        for (int j = 1; j <= n; ++j) {
            pref[bit][j] = pref[bit][j - 1] + (a[j] >> bit & 1);
        }
    }

    int q; cin >> q;
    while (q--) {
        int st, k; cin >> st >> k;

        int l = st, r = n, mid, ans = -1;
        while (l <= r) {
            mid = l + (r - 1) / 2;

            int andValue = 0;
            for (int bit = 0; bit < 32; ++bit) {
                int countOnes = pref[bit][mid] - pref[bit][st - 1];
                if (countOnes == mid - st + 1) andValue += 1LL << bit;
            }

            if (andValue >= k) ans = mid, l = mid + 1;
            else r = mid - 1;
        }

        cout << ans;
    }
}

void magic() {
    int n, l, r, x; cin >> n >> l >> r >> x;

    vector<int> c(n);
    for (int &i: c) cin >> i;

    int ans = 0;

    for (int mask = 0; mask < 1 << n; ++mask) {
        // mask: represents a subset
        // 1: take
        // 0: leave

        int sum = 0, mn = 1e9, mx = -1e9;
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                sum += c[i];
                mn = min(mn, c[i]);
                mx = max(mx, c[i]);
            }
        }

        if (sum >= l && sum <= r && mx - mn >= x)
            ans++;
    }

    cout << ans << endl;
}

int main() {


}