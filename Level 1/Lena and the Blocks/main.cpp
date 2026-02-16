//link :https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/I
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int MAXN=1e5;

int main() {
    int n;cin>>n;
    vector<int>heights(n);
    int mini=INT_MAX;
    int maxi=0;
    for (int i=0;i<n;++i) {
        cin>>heights[i];
        mini=min(mini,heights[i]);
        maxi=max(maxi,heights[i]);
    }
    if (mini==maxi) {
        cout<<0<<ln;
        return 0;
    }
    int diff=0,minDiff=1e9;
    int lastMini=-1,lastMaxi=-1;

    for (int i=0;i<n;++i) {
        if (heights[i]==mini)lastMini=i;

        if (heights[i]==maxi)  lastMaxi=i;
        if (lastMaxi!=-1 && lastMini!=-1) {
            diff=abs(lastMini-lastMaxi);
            minDiff=min(diff,minDiff);
        }
    }



    cout<<minDiff<<endl;

    return 0;
}
