#include <bits/stdc++.h>
using namespace std;
int n;
int headId;
int maxtime=0;
vector<int>manager;
vector<int>infoTime;
vector<int>timeA;
vector<vector<int>>subOrdinates;
void BFS(int start) {
    queue <int> q;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        maxtime=max(maxtime,timeA[curr]);
        for (int child:subOrdinates[curr]){
            q.push(child);
            timeA[child] = timeA[curr] + infoTime[curr];
        }
    }
}

int main() {
cin>>n;
cin>>headId;
manager.resize(n);
infoTime.resize(n);
timeA.resize(n,-1);
timeA[headId]=0;
subOrdinates.resize(n);
for(int i=0;i<n;i++)cin>>manager[i];
for(int i=0;i<n;i++)cin>>infoTime[i];
    for (int i=0;i<n;i++) {
        int child=i;
        int parent=manager[i];
        if (manager[i]==-1) {
            continue;
        }
        subOrdinates[parent].push_back(child);
    }
BFS(headId);
    cout << maxtime << endl;

}