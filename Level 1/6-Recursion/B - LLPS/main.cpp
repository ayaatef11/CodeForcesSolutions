// #include <bits/stdc++.h>
// using namespace std;
// int n,k,a,b;
// #define ll long long
// const int MAXN=2e9+5;
// // int costE(int x) {
// //     if (x==1)return 0;
// //     if (dp.count(x))return dp[x];
// //     int op1=costE(x-1)+a;
// //     int op2=1e9;
// //     if (x%k==0) {
// //         op2=costE(x/k)+b;
// //     }
// //     return dp[x]=min(op1,op2);
// // }
// int main() {
// cin>>n>>k>>a>>b;
//  int minCost =0;
//     if (k == 1) {
//         cout << (n - 1) * a << endl;
//         return 0;
//     }
//  while (n>1) {
//      if (n < k) {
//          minCost += (n - 1) * a;
//          break;
//      }
//       int rem=n&k;
//       n-=rem;
//       minCost+=rem*a;
//
//      if (b < a * k) {
//          minCost+=b;
//          n /= k;
//      } else {
//          minCost+=(n-1)*a;
//          break;
//      }
//  }
//    cout<<minCost<<endl;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k, a, b;
    cin>>n>>k>>a>>b;

    long long minCost = 0;

    if (k==1) {
        cout<<(n-1)*a << endl;
        return 0;
    }

    while (n > 1) {
        if (n < k) {
            minCost+=(n-1)*a;
            break;
        }

        long long remainder = n % k;
        minCost+=remainder*a;
        n-=remainder;
        if (b<a*k) {
            minCost+=b;
            n/=k;
        } else {
            minCost+=(n-1)*a;
            break;
        }
    }

    cout<<minCost<<endl;
    return 0;
}