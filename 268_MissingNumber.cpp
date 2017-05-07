#include "leetcode.h"
class Solution {
public:
    // 268. Missing Number
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        int total = n * (n + 1) / 2;
        return total - sum;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {0,1,2,4};
    auto ans = s1.missingNumber(nums);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
