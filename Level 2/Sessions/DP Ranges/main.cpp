#include <iostream>
using namespace std;
const int N=1001;
int dp[N][N][2];
int dp2[N][N];
int k;
int arr[N];
bool visited[N][N][2];
bool visited2[N][N];

int n;
//we want to split array into ranges +,- and get the maximum sum possible
//most consecutive ranges need l and r

int func(int l , int r, bool sign) {
    //handle invalid state before base case
    if (r-l+1>k) {
        return -1e18;
    }
    if (r==n)return 0;
    int & ret=dp[l][r][sign];
    if (visited[l][r][sign])return ret;
    visited[l][r][sign]=true;
    int gain=sign?-arr[r]:arr[r];
    int choice1=func(l,r+1,sign);
    int choice2=func(r+1,r+1,sign^1);
return ret= max(choice1,choice2)+gain;
}

int func2(int l , int r, int maxi) {//but here the range of maxi is big, it gots 1e9 and the array wont fill
    //handle invalid state before base case
    if (r-l+1>k) {
        return -1e18;
    }
    if (r==n) {
        if (l==n)return 0;
        return -1e18;
    }
    int & ret=dp[l][r][maxi];
    if (visited[l][r][maxi])return ret;
    visited[l][r][maxi]=true;
    int choice1=func(l,r+1,max(maxi,arr[r+1]))+0;
    int choice2=func(r+1,r+1,arr[r+1])+maxi*(r-l+1);
    return ret= max(choice1,choice2);
}
int func2_optimized(int l , int r, int maxi) {//maxi here is dpenedent of l and r , so we dont need to save it in the dp
    //handle invalid state before base case
    if (r-l+1>k) {
        return -1e18;
    }
    if (r==n) {
        if (l==n)return 0;
        return -1e18;
    }
    int & ret=dp2[l][r];
    if (visited2[l][r])return ret;
    visited2[l][r]=true;
    int choice1=func(l,r+1,max(maxi,arr[r+1]))+0;
    int choice2=func(r+1,r+1,arr[r+1])+maxi*(r-l+1);
    return ret= max(choice1,choice2);
}
int prefix[N];
int nested_func(int l, int r) {//o(n^3)why , because it have two states then it is o(n^2) and have a loop inside which is o(n)
    if (l>=r)return 0;
    int ans =1e15;

    for ( int k=l;k<r;++k) {
        ans=min(ans,nested_func(l,k)+nested_func(k+1,r));
    }
    return ans+prefix[r]-(l?prefix[l-2]:0);
}
int general_fnc(int l , int r,int k) {
    if (l>r)return 0;
    int & ret=dp2[l][r];
    if (~ret)return ret;
    int choice1=general_fnc(l+1,r,k+1);+arr[l]*k;
    int choice2=general_fnc(l,r+1,k+1);+arr[r]*k;
    return ret=max(choice1,choice2);
}
string s;

bool is_palindrome(int l,int r) {
    if (l>=r)return true;
    return s[l]==s[r]&& is_palindrome(l+1,r-1);
}
int main() {
int ans=max(func(0,0,0),func(0,0,1));
    //for nested_func
for (int i=0;i<n;i++) {
    cin>>arr[i];
    prefix[i]=arr[i];
    if (i)prefix[i]+=prefix[i-1];
}
    nested_func(0,n-1);
cout<<ans<<endl;
}