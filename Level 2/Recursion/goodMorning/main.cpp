#include <bits/stdc++.h>
using namespace std;

map<char, pair<int, int>> pos = {
    {'1',{0,0}},{'2',{0,1}},{'3',{0, 2}},
    {'4',{1,0}},{'5',{1,1}},{'6',{1, 2}},
    {'7',{2,0}},{'8',{2,1}},{'9',{2, 2}},
    {'0',{3,1}}
};
bool canEnter(int num) {
    string s =to_string(num);
    for (int i = 0; i + 1 < s.size(); i++) {
        auto [r1,c1]=pos[s[i]];
        auto [r2,c2]=pos[s[i + 1]];
        if (r2<r1||c2<c1) return false;
    }
    return true;
}

int findClosest(int k, int d = 0) {
    if (d > 300) return -1;
    int left=k-d;
    int right=k+d;
    if (left>=0&&canEnter(left))return left;
    if (canEnter(right))return right;
    return findClosest(k, d + 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        cout << findClosest(k) << endl;
    }
    return 0;
}
