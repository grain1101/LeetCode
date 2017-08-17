// 494. Target Sum
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ret = 0;
        dfs(ret, nums, target, 0, 0);
        return ret;
    }
    void dfs(int& ret, vector<int>& nums, int target, int cur, int idx) {
        if (idx == nums.size()) {
            if (cur == target) ret++;
            return;
        }
        dfs(ret, nums, target, cur + nums[idx], idx + 1);
        dfs(ret, nums, target, cur - nums[idx], idx + 1);
    }
    int findTargetSumWaysDp(vector<int>& nums, int target) {    
        int S = 1<<10;
        if(nums.empty() || target > S) return 0;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2 * S, 0));
        dp[0][S] = 1;
        for(int i = 1; i <= nums.size(); i++) {
            for(int j = 0; j < 2 * S; j++) {
                if (j - nums[i - 1] >= 0) dp[i][j] += dp[i - 1][j - nums[i - 1]];
                if (j + nums[i - 1] < 2 * S) dp[i][j] += dp[i - 1][j + nums[i - 1]];
            }
        }
        return dp[nums.size()][S + target];
    }
};