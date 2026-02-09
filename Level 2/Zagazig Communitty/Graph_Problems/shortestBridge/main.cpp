#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    unordered_set<long long> visit;

    bool invalid(int r, int c) {
        return r < 0 || c < 0 || r >= N || c >= N;
    }

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (invalid(r, c) || grid[r][c] == 0 || visit.count((long long)r * N + c))
            return;

        visit.insert((long long)r * N + c);
        for (auto& dir : directions)
            dfs(grid, r + dir[0], c + dir[1]);
    }

    int bfs(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (auto v : visit)
            q.push({v / N, v % N});

        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c] = q.front(); q.pop();
                for (auto& dir : directions) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (invalid(nr, nc) || visit.count((long long)nr * N + nc))
                        continue;

                    if (grid[nr][nc] == 1)
                        return res;

                    q.push({nr, nc});
                    visit.insert((long long)nr * N + nc);
                }
            }
            res++;
        }
        return -1;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        N = grid.size();
        bool found = false;

        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (grid[r][c] == 1) {
                    dfs(grid, r, c);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        return bfs(grid);
    }
};
