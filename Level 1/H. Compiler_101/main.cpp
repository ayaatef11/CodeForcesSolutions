#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main() {
fast();
    int n;cin>>n;
    vector<ll>a(n);
    ll max_or=0;
    for(int i=0;i<n;++i) {
        cin>>a[i];
        max_or|=a[i];
    }
    // if (max_or ==0) {
    //     cout<<1;
    //     return 0;
    // }
vector<ll>bit_count(30,0);
    int l=0;
    ll current_or=0;
int ans=n;

for (int r=0;r<n;++r) {
    //add a[right]
    for (int b=0;b<30;++b) {//loop over all bits of the number
        if (a[r]&(1LL<<b)) {//check if bit is one, make it LL as it caused runtime error
            bit_count[b]++;//update its frequency
            current_or|=(1LL<<b);//update current or
        }
    }
    //try to shrink
    while (l<=r&&current_or==max_or) {
        ans=min(ans,r-l+1);
        for (int b=0;b<30;++b) {
            if(a[l]&(1LL<<b)){
                bit_count[b]--;
                if(bit_count[b]==0)  current_or &=~(1LL<<b);///make the bit equal to 0
            }
        }
        l++;
    }
}
    cout<<ans;

    return 0;
}
