//link : https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/P
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool valid(vector<int>& freq){
    for(int i=0;i<=10;i++){
        if(freq[i]==0) return false;
    }
    return true;
}

int main() {
    ll t;
    cin >> t;

    for(int tc=1; tc<=t; tc++){
        string s;
        cin >> s;
        ll n = s.size();

        vector<int> nums;
        vector<int> pos;

        for(int i=0; i<n;){
            if(i+1<n && s[i]=='1' && s[i+1]=='0'){
                nums.push_back(10);
                pos.push_back(i+1);
                i += 2;
            } else {
                nums.push_back(s[i]-'0');
                pos.push_back(i);
                i++;
            }
        }

        int m = nums.size();
        vector<int> freq(11,0);

        int l=0;
        int bestLen = INT_MAX;
        int bestL=-1, bestR=-1;

        for(int r=0; r<m; r++){
            freq[nums[r]]++;

            while(valid(freq)){
                int currentLen = pos[r] - pos[l] + 1;
                if(currentLen < bestLen){
                    bestLen = currentLen;
                    bestL = pos[l]-(nums[l]==10 ? 1 : 0);;
                    bestR = pos[r];
                }

                freq[nums[l]]--;
                l++;
            }
        }

        cout << "Case " << tc << ": ";
        if(bestL == -1)
            cout << "NO\n";
        else
            cout << "YES " << bestL + 1 << " " << bestR + 1 << "\n";
    }

    return 0;
}
