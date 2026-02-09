#include <bits/stdc++.h>
using namespace std;
int main() {
int n;cin>>n;
    vector<int>coins(n);
for (int i = 0; i < n; i++)cin>>coins[i];
    set<int>sum;
    sum.insert(0);
    for (int i = 0; i < n; i++) {
        vector<int> new_sums;
        for (int s : sum) {
            new_sums.push_back(s + coins[i]);
        }
        for (int s : new_sums) {
            sum.insert(s);
        }
    }
sum.erase(0);
    cout<<sum.size()<<endl;
    for (auto i : sum)cout<<i<<" ";
}