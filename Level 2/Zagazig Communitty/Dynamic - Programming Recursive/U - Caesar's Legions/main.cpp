#include <bits/stdc++.h>
using namespace std;
const int MOD=1e8;
int dp[101][101][3][11];
int n1,n2,k1,k2;
//make lastChoice either 0 or 1 and keep its sstate , compare it with k1 or k2
//if 0 it is n1 and if 1 it is n2
int solve(int foot,int horse,int lastChoice,int repetition){
if(foot==0&&horse==0)return 1;
if((lastChoice==0 &&repetition>k1) || (lastChoice==1&&repetition>k2))return 0;
    if (dp[foot][horse][lastChoice][repetition]!=-1)return dp[foot][horse][lastChoice][repetition];
int res=0;
if(foot>0 ){
if(lastChoice==0){
if(repetition<k1)res+=solve(foot-1,horse,0,repetition+1)%MOD;//use foot
}
else{
    res+=solve(foot-1,horse,0,1)%MOD;
}
}
    if(horse>0 ){
if(lastChoice==1){
        if(repetition<k2){
            res+=solve(foot,horse-1,1,repetition+1)%MOD;//use foot
        }
}else{
            res+=solve(foot,horse-1,1,1)%MOD;//use noting

        }
    }

return dp[foot][horse][lastChoice][repetition]=res%MOD;
}

int main() {
cin>>n1>>n2>>k1>>k2;
    memset(dp,-1,sizeof(dp));
cout<<solve(n1,n2,0,0);

}