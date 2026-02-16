#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool canRemoveAllBoxes(const vector<int>&piles, int m, long long t) {
    ll requiredStudents = 0;
    ll n = piles.size();
    for (int i = 0; i < n; i++) {
        if (piles[i] > t - (i+1)) return false;
        ll boxesLeft = piles[i];
        ll timeAvailable = t - (i+1);
        ll studentsNeeded = (boxesLeft + timeAvailable - 1) / timeAvailable;
        requiredStudents += studentsNeeded;
        if (requiredStudents > m) return false;
    }
    return true;
}

int main() {
    int n,m;cin>>n>>m;
    vector<int>piles(n);
    for (int i=0;i<n;++i)cin>>piles[i];

    ll low = 0, high = 1e14,result = -1;
    while (low <= high) {
        long long mid = low+(high-low)/2;
        if (canRemoveAllBoxes(piles, m, mid)) {
            result = mid;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }

    cout<<result<<endl;
    return 0;
}