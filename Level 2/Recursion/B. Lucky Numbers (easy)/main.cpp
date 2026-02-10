#include <bits/stdc++.h>
using namespace std;
#define ll long long
int digits(ll num) {
    if (num == 0)   return 0;
    int digit = 0;
    while (num) {
        num /= 10;digit++;
    }
    return digit;
}
bool superLucky(ll num) {
    if (num == 0) return false;
    int sevens=0,fours=0;
    while (num) {
        if (num % 10 ==4)fours++;
        else if ( num%10==7) sevens++;
        else return false;
        num /= 10;
    }
    return sevens==fours;
}
set<ll>nums;
void solve(int digitNum,ll current,int baseDigit) {
    if (digitNum < 0) return ;
   solve(digitNum-1,current *10+7,baseDigit);
   solve(digitNum-1,current*10+4,baseDigit);
    if (superLucky(current)&&digits(current)>=baseDigit)nums.insert(current);
}
int main() {
int num;cin>>num;
int digitNum=digits(num);
    solve(digitNum,0,digitNum);

    auto it=nums.lower_bound(num);
    if (it!=nums.end()) {
        cout<<*it<<endl;
    }else {
 if (digitNum &1)digitNum++;
        else digitNum+=2;
        for (int i=0;i<digitNum;i++) {
            if (i<digitNum/2)  cout<<4;
            else cout<<7;
        }
    }
}