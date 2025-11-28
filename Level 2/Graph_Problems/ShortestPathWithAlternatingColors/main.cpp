#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> redGraph(n), blueGraph(n);
        for (auto &e:redEdges)redGraph[e[0]].push_back(e[1]);
        for (auto &e:blueEdges)blueGraph[e[0]].push_back(e[1]);
        vector<vector<int>>dist(n, vector<int>(2, INT_MAX));
        queue<pair<int,int>>q;
        q.push({0, 0});
        q.push({0, 1});
        dist[0][0] = dist[0][1] = 0;
        while (!q.empty()) {
            auto [node,color]=q.front();
            q.pop();
            int nextColor = 1 - color;
            vector<int> &nextEdges=(nextColor == 0)?redGraph[node]:blueGraph[node];
            for (int nei:nextEdges) {
                if (dist[nei][nextColor]==INT_MAX) {
                    dist[nei][nextColor]=dist[node][color]+1;
                    q.push({nei, nextColor});
                }
            }
        }
        
        vector<int> answer(n);
        for (int i=0;i<n;++i) {
            int d=min(dist[i][0], dist[i][1]);
            answer[i]=(d==INT_MAX?-1:d);
        }
        return answer;
    }
};
