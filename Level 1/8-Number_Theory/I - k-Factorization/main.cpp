#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
vector<int>factors;
void getFactors(int n){
int x=n;
for(int i=2;i<= x/i;i++){
while(n%i==0){
factors.push_back(i);
n/=i;
}
}
    if (n > 1) factors.push_back(n);//so importantt
}
int main() {
int n,k;cin>>n>>k;
getFactors(n);
int sz=factors.size();
if(k>sz){
cout<<-1<<ln;
return 0;
}
for(int i=0;i<k-1;i++)cout<<factors[i]<<" ";
int lastFactor=1;
for(int i=k-1;i<sz;i++){lastFactor*=factors[i];}
cout<<lastFactor<<ln;


}