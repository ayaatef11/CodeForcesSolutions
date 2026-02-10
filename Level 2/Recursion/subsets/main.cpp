#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<vector<int>> res;

void backtrack(int start, vector<int>& current) {
    if (!current.empty()) res.push_back(current);
    for (int i = start; i < arr.size(); i++) {
        current.push_back(arr[i]);
        backtrack(i + 1, current);
        current.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    vector<int> current;
    backtrack(0, current);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
            if (j < res[i].size() - 1) cout << " ";
        }
        if (i < res.size() - 1) cout << "\n";
    }
}
