//link : https://codeforces.com/group/T3p02rhrmb/contest/343396/problem/X
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
int t;cin>>t;

    int l=1,r =t;
    int ans =0;
    while (l<r) {
        int m = (r+l)/2;
        cout<<m<<endl;
        cout.flush();
        string  c;cin>>c;
        if (c=="<")            r=m-1;
        else  {
            l=m+1;
            ans=l;
            cout<<ans<<endl;
        }
    }
    cout<<"! "<<ans;

}