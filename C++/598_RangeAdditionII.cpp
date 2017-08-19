#include "leetcode.h"

// 598. Range Addition II
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a = m, b = n;
        for(int i = 0; i < ops.size(); i++){
            a = min(a, ops[i][0]);
            b = min(b, ops[i][1]);
        }
        return a * b;
    }
};

int main() {
    Solution s1;
    vector<vector<int>> nums = {{3,3},{3,3}};
    auto ans = s1.maxCount(3, 3, nums);
    cout << ans << endl;
}
