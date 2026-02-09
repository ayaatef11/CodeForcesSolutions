#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while (q--) {
        string type;
        int x;
        cin >> type >> x;

        if (type == "next_permutation") {
            while (x--) {
                if (!next_permutation(s.begin(), s.end())) {
                    sort(s.begin(), s.end());
                }
            }
        }
        else if (type == "prev_permutation") {
            while (x--) {
                if (!prev_permutation(s.begin(), s.end())) {
                    sort(s.rbegin(), s.rend());
                }
            }
        }

        cout << s << "\n";
    }

    return 0;
}
