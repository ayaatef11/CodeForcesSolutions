#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int dp[N][3]; // dp[i][last] => أقل عدد أيام راحة من اليوم i لو آخر حاجة عملتها = last

int n;
vector<int> a;

// last = 0 → راحة
// last = 1 → مسابقة
// last = 2 → رياضة
int cnt(int i, int last) {
    if (i == n) return 0; // لو خلصنا كل الأيام

    int &p = dp[i][last];
    if (p != -1) return p;

    // اليوم i
    if (a[i] == 0) {
        // اليوم لا جيم ولا مسابقة → راحة حتمية
        return p = cnt(i + 1, 0) + 1;
    }

    if (a[i] == 1) {
        // اليوم فيه مسابقة فقط
        if (last == 1) // ممنوع مسابقة يومين ورا بعض
            return p = cnt(i + 1, 0) + 1;
        return p = cnt(i + 1, 1); // ناخد مسابقة اليوم
    }

    if (a[i] == 2) {
        // اليوم فيه رياضة فقط
        if (last == 2) // ممنوع رياضة يومين ورا بعض
            return p = cnt(i + 1, 0) + 1;
        return p = cnt(i + 1, 2); // نعمل رياضة اليوم
    }

    if (a[i] == 3) {
        // اليوم فيه رياضة ومسابقه
        if (last == 1) return p = cnt(i + 1, 2); // لو أمس مسابقة → نعمل رياضة
        if (last == 2) return p = cnt(i + 1, 1); // لو أمس رياضة → نعمل مسابقة
        // لو أمس كان راحة → نختار أقل واحد بين مسابقة أو رياضة
        return p = min(cnt(i + 1, 1), cnt(i + 1, 2));
    }

    return 0;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));
    cout << cnt(0, 0) << endl; // نبدأ من اليوم الأول وراحة قبلها
}

int main() {
    solve();
    return 0;
}
