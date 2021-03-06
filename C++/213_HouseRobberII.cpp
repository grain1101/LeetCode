class Solution {
public:
    // 213. House Robber II
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        return max(rob_line(vector<int>(nums.begin(), nums.end() - 1)),
                   rob_line(vector<int>(nums.begin() + 1, nums.end())));
    }
    int rob_line(vector<int> nums){
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> f(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            if (i < 2) f[i] = nums[i];
            else if (i == 2) f[i] = nums[i] + nums[i - 2];
            else f[i] = max(f[i - 2], f[i - 3]) + nums[i];
        }
        return max(f[nums.size() - 1], f[nums.size() - 2]);
    }
};

int main() {
    Solution s1;
    vector<int> nums = {};
    auto ans = s1.rob(nums);
    showV(ans);
}
