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
//product rule
void productRule() {
    char letters[] = "BC";
    char answer[4];
    answer[3] = '\0';

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                answer[0] = letters[i];
                answer[1] = letters[j];
                answer[2] = letters[k];
                cout<<answer<<"\n";
            }
        }
    }
}

void inclusion_execlusion() {
    int n = 100;

    // المجموعات الفردية
    int f2 = n / 2;
    int f3 = n / 3;
    int f5 = n / 5;
    int f7 = n / 7;

    // التقاطعات الثنائية
    int f2_3 = n / (2*3);   // 16
    int f2_5 = n / (2*5);   // 10
    int f2_7 = n / (2*7);   // 7
    int f3_5 = n / (3*5);   // 6
    int f3_7 = n / (3*7);   // 4
    int f5_7 = n / (5*7);   // 2

    // التقاطعات الثلاثية
    int f2_3_5 = n / (2*3*5);   // 3
    int f2_3_7 = n / (2*3*7);   // 2
    int f2_5_7 = n / (2*5*7);   // 1
    int f3_5_7 = n / (3*5*7);   // 0

    int f2_3_5_7 = n / (2*3*5*7);  // 0

    int result = f2 + f3 + f5 + f7
                 - f2_3 - f2_5 - f2_7 - f3_5 - f3_7 - f5_7
                 + f2_3_5 + f2_3_7 + f2_5_7 + f3_5_7
                 - f2_3_5_7;

    cout << "Numbers count = " << result << endl;

    /*نجمع المجموعات الفردية (+)
    نطرح التقاطعات الثنائية (-)
    نجمع التقاطعات الثلاثية (+)
    نطرح التقاطعات الرباعية (-)*/
}
void brute_force_for_counting() {
    int n = 100;
    int cnt1 = 0;  // العداد

    // نمر على كل رقم من 1 إلى 100
    for (int i = 1; i <= n; ++i) {
        // لو الرقم يقبل القسمة على 2 أو 3 أو 5 أو 7
        if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
            ++cnt1;  // زود العداد
    }

    cout << cnt1 << "\n";  // النتيجة = 78
    //الفكرة: نفحص كل رقم واحد واحد، لو بيقبل القسمة على أي من الأرقام (2 أو 3 أو 5 أو 7) نعده.

}

void inclusion_exclusion_approach() {
    int cnt2 = 0;

    // 4 لوبات متداخلة لتوليد كل التوافيق الممكنة
    for (int i2 = 0; i2 <= 2; ++i2) {      // 2 موجود أو لا
        for (int i3 = 0; i3 <= 2; ++i3) {  // 3 موجود أو لا
            for (int i5 = 0; i5 <= 2; ++i5) {  // 5 موجود أو لا
                for (int i7 = 0; i7 <= 2; ++i7) {  // 7 موجود أو لا
                    int d = 1;  // المقام (الرقم اللي هنقسم عليه)
                    int elementsCnt = 0;  // عدد العناصر المختارة

                    // لو i2 = 2 يعني اخترنا الرقم 2
                    if(i2 == 2) { ++elementsCnt; d *= 2; }
                    if(i3 == 2) { ++elementsCnt; d *= 3; }
                    if(i5 == 2) { ++elementsCnt; d *= 5; }
                    if(i7 == 2) { ++elementsCnt; d *= 7; }

                    // لو ماختارناش أي رقم، نتجاهل
                    if(elementsCnt == 0)
                        continue;

                    // حساب الإشارة: إذا كان عدد العناصر فردي (+)، زوجي (-)
                    int sign = elementsCnt % 2 == 1 ? 1 : -1;

                    // نضيف أو نطرح حسب الإشارة
                    cnt2 += sign * n / d;
                }
            }
        }
    }

    cout << cnt2 << "\n";  // النتيجة = 78
}
//the recursive way for inclusion exclusion
    int primes[4] = {2, 3, 5, 7};  // الأعداد الأولية
    int nx = 100;

    // دالة عودية لحساب النتيجة
    int inc_exc(int idx = 0, int d = 1, int sign = -1) {
        // لو وصلنا لنهاية المصفوفة
        if(idx == 4) {
            // لو d = 1 يعني ما اخترناش أي رقم
            if(d == 1)
                return 0;  // لا نفعل شيء
            return sign * nx / d;
        }

        // خيارين:
        // 1. ما نختارش الرقم الحالي
        // 2. نختار الرقم الحالي
        return inc_exc(idx+1, d, sign) +
               inc_exc(idx+1, d * primes[idx], sign * -1);
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