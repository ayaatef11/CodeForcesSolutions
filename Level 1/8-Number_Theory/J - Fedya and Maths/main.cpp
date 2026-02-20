#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
int main() {
    string n;
    cin>>n;
    if (n=="0") {
        cout<<4<<"\n";
        return 0;
    }

    int mod=0;
    for (char c:n) {
        mod=(mod*10+(c-'0'))%4;
    }

    if (mod==0)
        cout<<4<<ln;
    else
        cout<<0<<ln;
}