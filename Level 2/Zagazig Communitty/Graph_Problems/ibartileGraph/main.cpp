#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        { 1, 3},
        {0, 2}
    };
    queue<int>q;
vector<int>colors(4,-1);
    for (int i = 0; i < graph.size(); i++) {
        if (colors[i] == -1) {
            q.push(i);
            colors[i] = 0;
            while (!q.empty()) {
                int start=q.front();
                q.pop();
                for (int neighbor : graph[start]) {
                    if (colors[neighbor] == -1) {
                        colors[neighbor] = 2-colors[start];
                        q.push(neighbor);
                    }else if (colors[neighbor]==colors[start]) {
                        cout<<"False";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "True";

}