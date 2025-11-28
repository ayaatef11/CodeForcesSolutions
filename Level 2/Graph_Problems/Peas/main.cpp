#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>> m;

 vector<long long>H(n+1);
 for(int i=1;i<=n;i++) {
     cin>>H[i];
 }

 vector<vector<int>>adj(n+1);

 for(int i=0;i<m;i++) {
     int A,B;
     cin>>A>>B;
     adj[A].push_back(B);
     adj[B].push_back(A);
 }
 int countGood=0;
    for(int i=1;i<=n;i++) {
        bool isGood=true;
        for(int neighbor:adj[i]) {
            if(H[neighbor]>=H[i]) {
                isGood=false;
                break;
            }
        }
        if(isGood)countGood++;
    }
    cout <<countGood<< "\n";
    return 0;
}
