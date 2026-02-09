#include <bits/stdc++.h>
using namespace std;

int main() {
int n;cin>>n;
    string s;cin>>s;
    string ans=s;
    int mid=n/2;
    for (int i=0;i<n/2;i++) {
      if (i &1)  ans[i]=s[mid-i];
      else ans[i]=s[mid+i];
    }
cout<<ans<<endl;
}