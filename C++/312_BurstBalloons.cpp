#include "leetcode.h"

const int N = 512;
const int M = 128;
class Solution {
public:
    // 312. Burst Balloons
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        num = {1, 1};
        auto it = num.begin();
        ++it;
        num.insert(it, nums.begin(), nums.end());
        dp.assign(num.size(), vector<int>(num.size(), -1));
        return dfs(0, num.size() - 1);
    }
    int dfs(int l, int r) {
        if (l > r) return 0;
        int &ret = dp[l][r];
        if (ret != -1) return ret;
        ret = 0;
        for(int i = l+1; i < r; i++) {
            ret = max(ret, num[i] * num[l] * num[r] + dfs(l, i) + dfs(i, r));
        }
        return ret;
    }
    vector<int> num;
    vector<vector<int>> dp;
};

int main() {
    Solution s1;
    vector<int> nums = {3, 1, 5, 8};
    cout << Solution().maxCoins(nums) << endl;
//    showV(ans);
    //show(ans);
    //showV(ans);
}
