#include "leetcode.h"

class Solution {
public:
    // 334. Increasing Triplet Subsequence
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        cout << "call LIS" << endl;
        cout << LIS(nums) << endl;
        for(auto n : nums){
            if (n <= c1){
                c1 = n;
            } else if (n <= c2){
                c2 = n;
            } else {
                return true;
            }
        }
        return false;
    }
private:
    // LIS(Longest Increasing Subsequence)
    // DP O(nlogn)
    int LIS(vector<int>& nums){
        vector<int> dp(nums.size(), INT_MAX);
        for(int i = 0; i < nums.size(); i++){
            *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
        }
        return lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin();
    }
    // how many k in sorted nums;
    // upper_bound(nums.begin(), nums.end(), k) - lower_bound(nums.begin(), nums.end(), k);
};

int main() {
    Solution s1;
    vector<int> nums = {2,3,1,4, 5};
    auto ans = s1.increasingTriplet(nums);
    cout << ans << endl;
}
