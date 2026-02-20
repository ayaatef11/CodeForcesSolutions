#include <deque>
#include <iostream>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main() {
int n;cin>>n;
    string s;cin>>s;
    deque<ll> dq;
dq.push_back(n);
while (n--) {
   if ( s[n]=='L')dq.push_back(n);
    else if ( s[n]=='R')dq.push_front(n);
}
 for (auto x : dq) {
     cout<<x<<" ";
 }
}