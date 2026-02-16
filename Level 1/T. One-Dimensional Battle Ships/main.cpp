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
    ll n,k,a;cin>>n>>k>>a;

    ll m;cin>>m;

    vector<ll> shots(m);
    for (int i=0;i<m;++i)cin>>shots[i];

    set<ll> st;
    st.insert(0);
    st.insert(n + 1);

    auto calc = [&](ll len) {
        return (len + 1) / (a + 1);
    };

    ll total=calc(n);

    for (int i = 0; i < m; i++) {
        ll x = shots[i];

        auto it = st.upper_bound(x);
        ll right = *it;
        --it;
        ll left = *it;

        ll old_len = right - left - 1;
        total -= calc(old_len);

        ll left_len = x - left - 1;
        ll right_len = right - x - 1;

        total += calc(left_len);
        total += calc(right_len);

        st.insert(x);
        if (total < k) {
            cout << i + 1 <<ln;
            return 0;
        }
    }

    cout<<-1<<ln;
    return 0;
}
