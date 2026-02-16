//link : https://codeforces.com/group/3nQaj5GMG5/contest/374321/problem/J
#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool comp(const pair<string, ll>& a, const pair<string, ll>& b) {
    if (a.second==b.second) {
        return a.first<b.first;
    }
    return a.second>b.second;
};
int main() {
    int n;cin >>n;

    map<string,ll> trainee_points;

    for (int i=0;i<n;i++) {
        int m;cin>>m;
        double points=1000.0;
        for (int j=0;j<m;j++) {
            string s;cin>>s;
            trainee_points[s]+=round(points);//so importnt to use round
            points*=0.9;
        }
    }

    vector<pair<string,ll>>sorted_points(trainee_points.begin(),trainee_points.end());

    sort(sorted_points.begin(), sorted_points.end(),comp);

    cout<<sorted_points[0].first<<endl;
    for (const auto& p : sorted_points) {
        cout<<p.first<<" "<< p.second << endl;
    }

    return 0;
}
