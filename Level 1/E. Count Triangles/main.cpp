#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

int main() {
int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());//1 2 5 8 10 12
    int cnt=0;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            for (int k=j+1;k<n;k++) {
                if (a[k]<(a[j]+a[i]))cnt++;
                else break;
            }
        }
    }
    cout<<cnt;


}