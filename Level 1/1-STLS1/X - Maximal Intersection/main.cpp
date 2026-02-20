#include <iostream>
#include <vector>
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
    vector<pair<int,int>>a(n);
for (int i=0;i<n;i++) {
    cin>>a[i].first>>a[i].second;
}
    int ans=0;
    for (int i=0;i<n;i++) {
        int mxl=0,mnr=1e9;
        for (int j=0;j<n;j++) {
            if (i==j)continue;
            mxl=max(mxl,a[j].first);
            mnr=min(mnr,a[j].second);
        }
        ans=max(ans,mnr-mxl);
    }
    cout<<ans<<ln;
}