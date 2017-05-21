#include "leetcode.h"

// 416. Partition Equal Subset Sum
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums) sum += n;
        if (sum % 2 != 0) return false;
        sum /= 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i - 1]){
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,5,11,5};
    auto ans = s1.canPartition(nums);
    cout << ans << endl;
}
