https://codeforces.com/group/T3p02rhrmb/contest/343965/problem/‘
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
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    map<int,int>freq;
    int l=0,r=0;
    int distinct=0;
    int best_l=0,best_r=0,max_len=0;
while (r<n) {
    freq[a[r]]++;
    if (freq[a[r]]==1) distinct++;
    while (distinct>k) {
        freq[a[l]]--;
        if (freq[a[l]]==0) distinct--;
        l++;
    }
    if (r-l+1>max_len) {
        max_len=r-l+1;
        best_l=l;
        best_r=r;
    }
    r++;
}
    cout<<best_l+1<<" "<<best_r+1<<endl;
}