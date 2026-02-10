#include <bits/stdc++.h>
using namespace  std;
#define ll long long
int weight;
int target;
bool found=false;
void solve(int x) {
    if (found)return;
    if (x==target) {
found=true;
        return;
    }
    if (x<target) {
        return;
    }
    if (x%3!=0)return;
    solve(x/3);
    solve(2*x/3);
}
int main() {
    int t;cin>>t;
    while(t--) {
        cin>>weight>>target;
        if (target>weight) {
            cout<<"NO"<<endl;
        }else if (target==weight) {
            cout<<"YES"<<endl;
        }
        else {
            found =false;
            solve(weight);
            if (found) {
                cout<<"YES"<<endl;
            }else
                cout<<"NO"<<endl;
        }
    }
}