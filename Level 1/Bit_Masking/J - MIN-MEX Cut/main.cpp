#include <iostream>
using namespace std;
#define ln '\n'
#define ll long long

int main() {
int t;cin>>t;
    while(t--) {
        string s;cin>>s;
        int sum=0;
        for(int i=0;i<s.length();i++) {
            if (s[i]=='0') {
                sum+=1;
                i++;
                while (s[i]=='0' && i<s.length()) {
                    i++;
                }
            }
        }
        cout<<min(2,sum)<<ln;
    }

}