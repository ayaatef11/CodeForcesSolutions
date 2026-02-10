#include <iostream>
using namespace std;
#define ln '\n'
#define ll long long
ll getDivisorsSum(int n) {
    if (n==1)return 0;//take care of this
    ll sum =1;
    for (int i = 2; i <= n/i; i++) {
        if (n % i == 0){
            sum += i;
           if (i!=(n/i)) sum += n/i;//take care of this condition
            if (sum>n)return sum;
        }
    }
    return sum;
}

int main() {
int t;cin>>t;
    while (t--) {
        int x;cin>>x;
        ll result = getDivisorsSum(x);
        if (result == x) cout<<"perfect"<<ln;
       else if (result < x) cout<<"deficient"<<ln;
        else cout<<"abundant"<<ln;
    }
}