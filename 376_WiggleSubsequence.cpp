#include "leetcode.h"

// 376. Wiggle Subsequence
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int f = 1, d = 1;
        int n = nums.size();
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] > nums[i - 1]) f = d + 1;
            if (nums[i] < nums[i - 1]) d = f + 1;
        }
        return min(n, max(f, d));
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3};
    auto ans = s1.wiggleMaxLength(nums);
    cout << ans << endl;
}
