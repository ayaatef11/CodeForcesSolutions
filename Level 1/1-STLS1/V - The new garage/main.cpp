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
int n;cin>>n;
    queue<int> q;
    for (int i=0;i<n;i++) {
        int x;cin>>x;
        q.push(x);
    }
    stack<int> st;
    for (int i=1;i<=n;i++) {
        st.push(i);
        while (!st.empty() && st.top()==q.front()) {
            st.pop();
            q.pop();
        }
    }
    cout<<(q.empty()?"YES":"NO")<<ln;
}