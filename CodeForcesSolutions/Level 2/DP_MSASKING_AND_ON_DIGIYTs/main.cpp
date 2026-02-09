#include <bits/stdc++.h>
using namespace std;
const int N=10;
int dp[N+5][3][4];
string a;
//classy numbers
int rec(int idx, bool tight, int rem) {
    if (idx==a.size())return (rem==0);
    if (rem >3)return 0;

    int &ret = dp[idx][tight][rem];
    if (~ ret) {return ret;}
    ret=0;
    if (tight) {
        int en=a[idx]-'a';
        for (int i=0;i<=en;i++) {
            ret+=rec(idx+1,tight && (en==i),rem-(i!=0));
        }
    }else {
        int en=9;
        for (int i=0;i<=en;i++) {
            ret+=rec(idx+1,tight,rem-(i!=0));
        }
    }
    return ret;
}
int main() {
int t;cin>>t;
int l,r;cin>>l>>r;
a=to_string(r);
memset(dp,-1,sizeof(dp));
int ans=rec(0,0,0);
a=to_string(l);
memset(dp,-1,sizeof(dp));
ans-=rec( 0,0,0);
cout<<ans<<endl;
}