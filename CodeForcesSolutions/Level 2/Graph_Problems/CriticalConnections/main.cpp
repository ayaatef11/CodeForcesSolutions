#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>connections;
vector<bool>visited;
void DFS(int start) {
for (int i = start; i < n; i++) {
    if (!visited[i]) {
        DFS(i);
    }
}
}

int main() {
cin>>n;
connections.resize(n);
for (int i=0;i<connections.size();i++) {
    DFS(i);
}

}