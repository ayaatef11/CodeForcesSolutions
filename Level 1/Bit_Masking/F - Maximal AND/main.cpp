#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
bool checkBit(int x,int bit) {
    return (x>>bit)&1;
}

int main() {
int t;cin>>t;
    while(t--) {
        int n,k;cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for (int bit=30;bit>=0;bit--) {
            int cost =0;
            for (int i=0;i<n;i++) {
                if (!checkBit(a[i],bit)) {cost++;}
            }
            if (cost<=k) {
                k-=cost;
                for (int i=0;i<n;i++) {
                    a[i]|=(1<<bit);
                }
            }
        }
        int ans=-1;
        for (int i=0;i<n;i++)ans&=a[i];
        cout<<ans<<ln;
    }

}