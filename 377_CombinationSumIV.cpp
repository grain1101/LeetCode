#include "leetcode.h"

// 377. Combination Sum IV
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        sort (nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i < num) break;
                dp[i] += dp[i - num];
            }
        }
        return dp.back();
    }
    int combinationSum4_dfs(vector<int>& nums, int target) {
        ret = 0;
        this->nums = nums;
        this->target = target;
        for(int i = 0; i < nums.size(); i++){
            dfs(nums[i], i);
        }
        return ret;
    }
private:
    int ret;
    int target;
    vector<int> nums;
    void dfs(int sum, int level){
        if (sum == target) {
            ret++;
            return;
        }
        if (sum > target) return;
        dfs(sum + nums[level], level);
        for(int i = 0; i < nums.size(); i++){
            if (i == level) continue;
            dfs(sum + nums[i], i);
        }
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3};
    auto ans = s1.combinationSum4(nums, 4);
    cout << ans << endl;
}
