#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

int main() {
int n,m,k;cin>>n>>m>>k;
 vector<int> a(m+1);
 for (int i = 0; i <= m; i++)cin>>a[i];
int cnt=0;
 for (int i = 0; i <m; i++) {
  int bits=__builtin_popcount(a[i]^a[m]);
  if (bits<=k) cnt++;
 }
    cout<<cnt;
}