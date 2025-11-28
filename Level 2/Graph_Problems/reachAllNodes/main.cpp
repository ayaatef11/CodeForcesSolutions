class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0); 
        set<pair<int, int>> connected;

        // نحسب عدد الطرق المتصلة بكل مدينة ونخزن الطرق نفسها
        for (auto& r : roads) {
            int a = r[0], b = r[1];
            degree[a]++;
            degree[b]++;
            connected.insert({min(a, b), max(a, b)});
        }

        int maxRank = 0;

        // نجرب كل زوج من المدن
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];
                if (connected.count({i, j})) rank--; // لأن الطريق بينهم يُحسب مرة واحدة فقط
                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;
    }
};
