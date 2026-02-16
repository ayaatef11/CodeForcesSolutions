#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
string s;
bool isPalindromic(int l , int r) {
    if (l > r) return true;
    if (s[l]!=s[r]) return false;
    return isPalindromic(l+1, r-1);
}
vector<string>palindromic;
void generate(int l, int r) {
int n=s.size();
    if (l==n)return;
    if (r==n) {
        generate(l+1,l+1);
        return;
    }
    if (isPalindromic(l, r)) {
        palindromic.push_back(s.substr(l,r-l+1));
    }

    generate(l,r+1);
}
int main() {
cin>>s;
generate(0,0);
sort(palindromic.begin(), palindromic.end());
    for (auto x : palindromic) {
        cout<<x<<ln;
    }
}