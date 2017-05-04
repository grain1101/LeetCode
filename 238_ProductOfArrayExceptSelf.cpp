#include "leetcode.h"
class Solution {
public:
    // 238. Product of Array Except Self
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 1);
        int fromBegin = 1;
        int fromEnd = 1;
        for(int i = 0; i < n; i++){
            ret[i] *= fromBegin;
            fromBegin *= nums[i];
            ret[n - 1 - i] *= fromEnd;
            fromEnd *= nums[n - i - 1];
        }
        return ret;
    }
};


int main() {
    Solution s1;
    vector<int> nums = {1,2,3,4};
    auto ans = s1.productExceptSelf(nums);
    //cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
