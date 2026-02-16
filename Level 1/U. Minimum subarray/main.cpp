//link : https://codeforces.com/group/3nQaj5GMG5/contest/372026/problem/U
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define int long long
//there is no grid that can be 1e^6 * 1e^6
//time and space complexity
// void preprocesQueries(vector<vector<ll>> &v) {
//     for (int i=0;i<v.size();i++) {
//         for (int j=0;j<v[i].size();j++) {
//             // if (i==0) {
//             //     if (j!=0) v[i][j]+= v[i][j-1];
//             // }
//             // else if (j==0)v[i][j]+=v[i-1][j];
//             // else  v[i][j]+=(v[i-1][j]+v[i][j-1]-v[i-1][j-1]);
//             //here is a clean code
//             if (i>0)v[i][j]+=v[i-1][j];
//             if (j>0)v[i][j]+=v[i][j-1];
//             if (i>0 && j>0)v[i][j]-=v[i-1][j-1];
//         }
//     }
// }
// ll  processQueries(int h , vector<vector<ll>> v) {
//     h--;
//     int n=(int)v.size();
//     ll maxCount=1e9;
//     ll count =0;
//
//     for (int i=0;i<n; i++) {
//         if (i+h>=n)break;
//         if (i==0)count=v[i+h][n-1];
//         else count=v[i+h][n-1]-v[i-1][n-1];
//         maxCount=min(count,maxCount);
//     }
//
//     return maxCount;
// }
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--) {
        int n,h;cin>>n>>h;
        vector<int>arr(n,n);
        vector<int>diff(n,0);
        for (int i=0;i<n;i++) {
            int l,r;cin>>l>>r;
            l--,r--;
            diff[l]-=1;
            if (r<n-1) diff[r+1]+=1;
        }

        for (int i=0;i<n;i++) {
            if (i>0) diff[i]+=diff[i-1];
            arr[i]+=diff[i];
            if (i>0)arr[i]+=arr[i-1];
        }

        // for (int i=0;i<n;i++)cout<<arr[i]<<" ";
        // cout<<endl;
        //get max val

        h--;
        ll maxCount=LLONG_MAX;
        ll count =0;

        for (int i=0;i<n; i++) {
            if (i+h>=n)break;
            if (i==0)count=arr[i+h];
            else count=arr[i+h]-arr[i-1];
            maxCount=min(count,maxCount);
        }
        cout<<maxCount<<ln;

    }
}