#include <bits/stdc++.h>
using namespace std;

long long n;
int ans = 0;

void dfs(long long num) {
    if (num > n) return;
    if (num != 0) ans++;

    dfs(num * 10 + 0);
    dfs(num * 10 + 1);
}

int main() {
    cin >> n;
    dfs(0);
    cout << ans << endl;
}
