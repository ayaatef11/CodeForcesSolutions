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
    int n, m;cin>>n>>m;
    vector<deque<ll>>st(m);
    vector<int>freq(n+1,0);
    vector<pair<int,int>>acc(n+1,{-1,-1}); // not taken

    for(int i=0;i<m;i++) {
        int k;cin>>k;
        st[i].resize(k);
        for(int j=0;j<k;j++) {
            ll c;cin>>c;
            st[i][j]=c;
        }
    }
    for(int i=0;i<m;i++) {
        if(!st[i].empty()) {
            int topColor=st[i].front();
            freq[topColor]++;
            if(acc[topColor].first==-1)acc[topColor].first=i;
            else acc[topColor].second=i;
        }
    }

    stack<int>st2;
    for(int i=1;i<=n;i++) {
        if(freq[i]==2)st2.push(i);
    }
    int cnt=0;
    while(!st2.empty()) {
        int c=st2.top();
        st2.pop();
        cnt++;
        int a=acc[c].first;
        int b=acc[c].second;
        st[a].pop_front();
        st[b].pop_front();
        acc[c]={-1,-1};
        freq[c]=0;

        if(!st[a].empty()) {
            int newTop=st[a].front();
            freq[newTop]++;
            if(acc[newTop].first==-1)acc[newTop].first=a;
            else acc[newTop].second=a;
            if(freq[newTop]==2) st2.push(newTop);
        }

        if(!st[b].empty()) {
            int newTop = st[b].front();
            freq[newTop]++;
            if(acc[newTop].first == -1) acc[newTop].first = b;
            else acc[newTop].second = b;
            if(freq[newTop]==2) st2.push(newTop);
        }
    }

    cout <<(cnt==n?"Yes":"No")<< ln;
    return 0;
}