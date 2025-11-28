#include <bits/stdc++.h>
using namespace std;

int n, t, sum;
set<string, greater<string>> ans;
vector<int> curr;
void Solve(int idx, vector<int>& arr) {
    if (idx == n) {
        if (sum == t) {
            string tmp = "";
            for (auto i:curr) {
                tmp += to_string(i);
                tmp += "+";
            }
            tmp.pop_back();
            ans.insert(tmp);
        }
        return;
    }
    sum += arr[idx];
    curr.push_back(arr[idx]);
    Solve(idx + 1, arr);
    sum -= arr[idx];
    curr.pop_back();
    Solve(idx + 1, arr);
}

int main() {
    while (cin >> t >> n && n) {
        vector<int> arr(n);
        for (int i=0;i<n;i++) cin >> arr[i];
        ans.clear();
        curr.clear();
        sum = 0;
        Solve(0, arr);
        cout <<"Sums of "<<t<< ":\n";
        if (ans.empty()) {
            cout << "NONE\n";
        } else {
            for (auto& s : ans)
                cout << s << "\n";
        }
    }

    return 0;
}
