#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> freq;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
bool check(ll mid,ll k,vector<ll>&temp){
    temp.clear();
    for(auto i : freq){
        ll div=i.second/mid;
        while(div--){
            temp.push_back(i.first);
            if(temp.size()==k)return true;
        }
    }
    return false;
}
int main() {
    fast();
    ll n,k;cin>>n>>k;
    vector<ll> arr(n);
    vector<ll>result;
    vector<ll>temp;
    for(ll i=0;i<n;i++)cin>>arr[i];
    for(ll i=0;i<n;i++)freq[arr[i]]++;
    ll l=1,r=n;
    while(l<=r){

        ll mid=l+(r-l)/2;
        if(check(mid,k,temp)){
            l=mid+1;
            result=temp;
        }else{
            r=mid-1;
        }
    }
    for(ll i=0;i<(ll)result.size();i++)cout<<result[i]<<" ";
    return 0;
}
