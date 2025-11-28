#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
set<string>res;
void solve(int i) {
 if (i == s.size()) {
res.insert(s);
     return;
 }
    solve(i+1);
    for (int j=i; j<s.size(); j++) {
swap(s[i],s[j]);
        solve(i+1);
        swap(s[i],s[j]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

cin>>s;
    solve(0);
    cout << res.size() << "\n";
    for (auto str : res) cout << str << "\n";

}