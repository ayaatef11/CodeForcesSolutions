#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isReserved(string num) {
    for (int i = 0; i < num.length(); i++) {
        if (num[i]>='2')return false;
    }
    return true;
}
int n;
int cnt;
void solve(int i) {
    if (i>n) return;
    if (isReserved(to_string(i))) { cnt++; }
    solve(i+1);
}
int main() {
    cin>>n;
    solve(1);
    cout<<cnt;
}