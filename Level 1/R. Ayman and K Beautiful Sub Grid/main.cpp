#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}
bool check(int len,int n, int m, int k,vector<vector<vector<int>>> &prefix,int &ansX,int &ansY) {
    for (int i = 1; i+len-1<= n;i++) {
        for (int j = 1;j+len-1<=m;j++) {
            int x1=i;
            int y1=j;
            int x2=i+len-1;
            int y2=j+len-1;

            int distinct=0;

            for (int c=0;c<26;c++) {
                int cnt =prefix[c][x2][y2]-prefix[c][x1 - 1][y2]-prefix[c][x2][y1 - 1]+ prefix[c][x1-1][y1-1];
                if (cnt > 0) distinct++;
            }

            if (distinct>=k) {
                ansX = x1;
                ansY = y1;
                return true;
            }
        }
    }

    return false;
}

int main() {
   fast();
    int n,m,k;cin>>n>>m>>k;

    vector<string>grid(n);
    for (int i=0;i<n;++i) cin>>grid[i];

    if (k>26) {
        cout<<-1<<ln;
        return 0;
    }

    vector<vector<vector<int>>> prefix(26,
        vector<vector<int>>(n+1, vector<int>(m + 1, 0)));

    for (int c = 0; c < 26; ++c) {
        for (int i = 1; i <= n;++i) {
            for (int j = 1; j <= m; ++j) {
                prefix[c][i][j]=prefix[c][i - 1][j]+ prefix[c][i][j - 1]-prefix[c][i - 1][j - 1];

                if (grid[i-1][j-1] == char('A' + c))prefix[c][i][j]++;
            }
        }
    }

    int low = 1, high = min(n, m);
    int ansLen = -1;
    int ansX = -1, ansY = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

    if (check(mid, n, m, k, prefix, ansX, ansY)) {
            ansLen=mid;
            high=mid-1;
        } else {
            low = mid + 1;
        }
    }

    if (ansLen == -1) {
        cout << -1 << "\n";
    } else {
        cout << ansLen << "\n";
        cout << ansX << " " << ansY << "\n";
    }

    return 0;
}
