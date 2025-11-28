#include<bits/stdc++.h>
using namespace  std;
class Solution {
public:
    unordered_map<int, bool> memo;

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;// sum of all numbers
        if (sum < desiredTotal) return false; // impossible
        if (desiredTotal <= 0) return true;   // already satisfied

        return dfs(maxChoosableInteger, desiredTotal, 0);
    }

    bool dfs(int maxInt, int target, int usedMask) {
        if (memo.count(usedMask)) return memo[usedMask];

        for (int i = 1; i <= maxInt; i++) {
            int curBit = 1 << (i - 1);
            if ((usedMask & curBit) == 0) {
                if (i >= target || !dfs(maxInt, target - i, usedMask | curBit)) {
                    return memo[usedMask] = true;
                }
            }
        }
        return memo[usedMask] = false;
    }
};
int main() {
    Solution s;
    int n,x;cin>>n>>x;
   cout<< s.canIWin(n,x);
}