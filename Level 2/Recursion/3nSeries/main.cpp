#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync
#define pb push_back
#define mp make_pair
void solve(int i,int& n) {
    n++;
    if (i==1)return;
    if (i%2==0)solve(i/2,n);
    else solve(i*3+1,n);
}

int main() {
int n;cin>>n;
    int x=0;
    solve(n,x);

    cout<<x;
}