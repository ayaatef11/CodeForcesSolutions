#include <iostream>
using namespace std;

long long sum_digits(long long x) {
    long long sum=0;
    while (x>0) {
        sum+=x%10;
        x/=10;
    }
    return sum;
}

int main() {
    long long n,s;
    cin>>n>>s;
    long long low=1,high=n,ans=n+1;

    while (low<=high) {
        long long mid=(low+high)/2;
        if (mid-sum_digits(mid)>=s) {
            ans=mid;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }

    cout<<(n-ans+1>0?n-ans+1:0)<<endl;

    return 0;
}