#include "leetcode.h"

// 254.Factor Combinations
class Solution {
public:
    // n = 12;
    //
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> path;
        helper(n, 2, path, result);
        return result;
    }
    void helper(int remain, int start, vector<int> path, vector<vector<int>> &result) {
        if (remain == 1) {
            if (path.size() > 1) result.push_back(path);
        } else {
            for (int i = start; i <= remain; ++i) {
                if (remain % i == 0) {
                    path.push_back(i);
                    helper(remain / i, i, path, result);
                    path.pop_back();
                }
            }
        }
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3};
    auto ans = s1.getFactors(12);
    show(ans);
    //cout << ans << endl;
}
