#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
int main() {
int t;cin>>t;
    while (t--) {
        int n;cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;i++) cin>>a[i];
        int ans=-1;//(1 << 30) - 1;//this is the idenity for and operation 11111... or we can say ans =-1
        for (int i=0;i<n;i++) {
            if ((a[i]^i)==0){continue;}
                ans &=(i & a[i]);//~(a[i]^i) it will cause -1 and this is wrong

        }
        cout<<ans<<ln;
    }

}