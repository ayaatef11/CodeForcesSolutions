#include <bits/stdc++.h>
#define ll long long
#define ln '\n'
const int MAXN=1e6+1;

using namespace std;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main() {
fast();
int n;cin>>n;
    vector<int>arr(n);
    vector<int>plus;
    vector<int>minus;
for (int i=0;i<n;i++) {
    cin>>arr[i];
    if (arr[i]>=0)plus.push_back(arr[i]);
    else minus.push_back(arr[i]);
}
    sort(plus.begin(),plus.end());sort(minus.begin(),minus.end(),greater<int>());
   int i=0,j=0;
    ll ans=0;
    vector<int>res;
    for (int i=0;i<n;i++) {
        ans+=arr[i];
    }
    if (!ans) {
        cout<<"NO";
        return 0;
    }
    ans =0;
    while (i<plus.size() && j<minus.size()) {
        ans+=plus[i];
        res.push_back(plus[i]);
        i++;
        if (abs(minus[j])!=ans) {
            ans+=minus[j];
            res.push_back(minus[j]);
            j++;
        }

    }
    while (i<plus.size()) {ans+=plus[i]; res.push_back(plus[i]);
        i++;}
    while (j<minus.size()) {
        int k=j;
        while (abs(minus[k])==ans && k<minus.size()) {
            swap(minus[k],minus[k+1]);
            k++;
        }
        ans+=minus[j];
        res.push_back(minus[j]);
        j++;
    }
    if (ans) {
        cout<<"YES"<<endl;
        for (int i=0;i<n;i++)cout<<res[i]<<" ";

    }

else cout<<"NO";
}