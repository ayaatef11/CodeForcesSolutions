#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s1,s2;
int n;
int calc(string s) {
    int sum=0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i]=='+')sum+=1;
        else if (s[i]=='-')sum-=1;
    }
    return sum;
}
vector<int>ans;
void solve(int i) {
   if (i==n) {
       int x=calc(s2);
       ans.push_back(x);
       return;
   }
   if (s2[i]=='?') {
       s2[i]='+';
       solve(i+1);
       s2[i]='-';
       solve(i+1);
       s2[i]='?';//backtrack
   }else
       solve(i+1);
}
int main() {
cin>>s1>>s2;
n=s1.length();
   int x= calc(s1);
    int j=0;

    solve(0);
    for (int i=0;i<ans.size();i++) {
        if (x==ans[i]) {
            j++;
        }
    }
    cout << fixed << setprecision(12);
    cout<<(double)j/ans.size()<<endl;
}