#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        if (m == 0) return {};
        int n = heights[0].size();

        vector<vector<bool>> reachP(m, vector<bool>(n, false));
        vector<vector<bool>> reachA(m, vector<bool>(n, false));

        // دلائل الاتجاهات (أعلى, أسفل, يسار, يمين)
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        auto bfs = [&](queue<pair<int,int>> &q, vector<vector<bool>> &visited) {
            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (visited[nr][nc]) continue;
                    // شرط "عكس التدفق": يمكننا الذهاب إلى الجار إذا كان ارتفاعه >= الارتفاع الحالي
                    if (heights[nr][nc] >= heights[r][c]) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        };

        // تهيئة طوابير البداية للمحيط الهادئ (Pacific): الصف الأول و العمود الأول
        queue<pair<int,int>> qP;
        for (int c = 0; c < n; ++c) {
            reachP[0][c] = true;
            qP.push({0, c});
        }
        for (int r = 0; r < m; ++r) {
            reachP[r][0] = true;
            qP.push({r, 0});
        }

        // تهيئة طوابير البداية للمحيط الأطلسي (Atlantic): الصف الأخير و العمود الأخير
        queue<pair<int,int>> qA;
        for (int c = 0; c < n; ++c) {
            reachA[m-1][c] = true;
            qA.push({m-1, c});
        }
        for (int r = 0; r < m; ++r) {
            reachA[r][n-1] = true;
            qA.push({r, n-1});
        }

        // تنفيذ BFS لكل محيط
        bfs(qP, reachP);
        bfs(qA, reachA);

        // جمع النتائج: تقاطع المجموعتين
        vector<vector<int>> result;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (reachP[r][c] && reachA[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};
