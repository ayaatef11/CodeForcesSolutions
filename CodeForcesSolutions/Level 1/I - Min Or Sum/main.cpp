#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
int setBitToZero(int& x, int bit) {
    return x &= ~(1 << bit);
}

void checkBits(int& x, int y) {
    for (int i=0; i<32; i++) {
        if ((x & (1 << i)) && (y & (1 << i))) {
            setBitToZero(x, i);
        }
    }
}
int main() {
int t;cin>>t;
    while(t--) {
        int n;cin>>n;
        vector<int> v(n);
        int sum=0;
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                checkBits(v[i], v[j]);
            }
        }
        for(int i=0;i<n;i++) sum+=v[i];
        cout<<sum<<ln;
    }

}