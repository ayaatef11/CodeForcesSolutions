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
    string recipe;
    cin >>recipe;
    ll nb,ns,nc;
    cin>>nb>>ns>>nc;
    ll pb,ps,pc;
    cin>>pb>>ps>>pc;
    ll r;
    cin >> r;
    ll rb=0,rs=0,rc=0;
    for (char c : recipe) {
        if (c=='B') rb++;
        else if (c =='S') rs++;
        else if (c == 'C') rc++;
    }
    auto canMake = [&](ll x) {
        __int128 need = 0;//for overflow
        if (rb * x > nb) need += (rb * x - nb) * pb;
        if (rs * x > ns) need += (rs * x - ns) * ps;
        if (rc * x > nc) need += (rc * x - nc) * pc;
        return need <= r;
    };
    ll start = 0, end = 1e13, ans = 0;
    while (start <= end) {
        ll mid = (start + end) / 2;
        if (canMake(mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << ans <<ln;
    return 0;
}
