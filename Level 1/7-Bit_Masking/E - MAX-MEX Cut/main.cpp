#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
int main() {
    int t;cin>>t;
    while (t--) {
        int bits;cin>>bits;
        string b1,b2;cin>>b1>>b2;
        int ans=0;
        for (int bit=0;bit<bits;bit++) {
            if (b1[bit]!= b2[bit]) {
                ans+=2;
            }
            else if (b1[bit]=='0') {
                ans+=1;
                if (bit!=bits-1 && b2[bit+1]=='1' && b1[bit+1]=='1') {
                    ans+=1;
                    bit++;
                }
            }else if (b1[bit]=='1') {
                if (bit!=bits-1 && b2[bit+1]=='0'&& b1[bit+1]=='0'){
                    ans+=2;
                    bit++;
                }
            }
        }
        cout<<ans<<ln;
    }


}