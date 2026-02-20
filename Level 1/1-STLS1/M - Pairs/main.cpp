#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
bool TRY(int x, vector<pair<int,int>>&a,int n) {
    vector<pair<int,int>>b;
    for(auto [i,j]:a) {
        if (i!=x && j!=x)b.emplace_back(i,j);
    }
    vector<int>freq(n+1);
    for (int i=0;i<b.size();i++) {
        freq[b[i].second]++;
        freq[b[i].first]++;
    }
    int mx=*max_element(freq.begin(),freq.end());
    if (mx==b.size())return true;
    return false;
}
int main() {
fast();
int n,m;cin>>n>>m;
    vector<pair<int,int>>a(m);
    for (int i=0;i<m;i++) {
        auto &[x,y]=a[i];
        cin>>x>>y;
    }
    if (TRY(a[0].first,a,n)|| TRY(a[0].second,a,m)) {
cout<<"YES"<<endl;
    }else
        cout<<"NO"<<endl;
}