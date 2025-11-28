#include <bits/stdc++.h>
using namespace std;
string stateSpace;
int path=0;
vector<char>genes={'A','C','G','T'};
vector<string>visited;

int BFS(string start,string end) {
queue<pair<string,int>>q;
    q.push(start,0);
    visited.push_back(start);
    while (!q.empty()) {
        auto[curr,steps] = q.front();
        q.pop();
        if (curr==end) {return steps;}
        for (int i = 0; i < curr.length(); i++) {
            if (stateSpace.at(i) == currentNode) {
                cout << currentNode << " ";
                q.push(currentNode + 1);

            }
        }
        path++;
    }
}

int main() {
set<string>bank;

}