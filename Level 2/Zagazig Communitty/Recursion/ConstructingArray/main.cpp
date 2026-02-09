#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int step;

auto cmp = [](pair<int,int> a, pair<int,int> b) {
    int lenA = a.second - a.first + 1;
    int lenB = b.second - b.first + 1;
    if (lenA == lenB)
        return a.first > b.first;
    return lenA < lenB;
};
void fillArray(priority_queue<pair<int,int>, vector<pair<int,int>>,decltype(cmp)>& segs) {
    if (segs.empty()) return;
    auto [l, r] = segs.top();
    segs.pop();
    int len =r-l+1;
    int mid =(len%2?(l+r)/2:(l+r-1)/2);
    v[mid] =step++;

    if (l<=mid-1)
        segs.push({l, mid - 1});
    if (mid+1<=r)
        segs.push({mid + 1, r});

    fillArray(segs);
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        v.assign(n, 0);
        step = 1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> segs(cmp);
        segs.push({0, n - 1});
        fillArray(segs);
        for (int x : v)
            cout<<x <<" ";
        cout << endl;
    }
}
