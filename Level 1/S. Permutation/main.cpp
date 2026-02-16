#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main() {
    fast();
    freopen("mex.in", "r", stdin);
    int t;cin>>t;
    vector<int> arr, prfx, sfx;
    while(t--){
        int n,q;cin>>n>>q;
arr.assign(n + 2, 0);
        prfx.assign(n + 2, 0);
        sfx.assign(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            prfx[i] = arr[i];
            sfx[i] = arr[i];
        }
        //build prefix min
        for (int i =2;i<=n;i++) {
            prfx[i]=min(prfx[i-1],prfx[i]);
        }
        //buidl suffix min
        for (int i =n-1;i>=1;i--) {
            sfx[i] = min(sfx[i], sfx[i+1]);
        }

        while (q--) {
            int l,r;cin>>l>>r;
            if (l==1&&r==n) cout << n +1;
             else if (l == 1)  cout << sfx[r + 1];
            else if (r == n)
                cout << prfx[l - 1];
            else  cout << min(prfx[l - 1], sfx[r + 1]);

            cout <<ln;
        }
    }
}