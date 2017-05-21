#include "leetcode.h"

// 594. Longest Harmonious Subsequence
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int ret = 0;
        int j = 0, tmp = nums[0];
        showV(nums);
        for(int i = 1; i < nums.size(); i++){
            if (i != nums.size() - 1 && (nums[i] == nums[i - 1] || nums[i] == tmp + 1)) continue;
            cout << j << " " << i << " " << tmp << endl;
            if (nums[i - 1] == tmp + 1) ret = max(ret, i - j);
            if (nums[i] == tmp + 1) ret = max(ret, i - j + 1);
            while(nums[j] == tmp) j++;
            tmp = nums[j];
        }
        if (nums[nums.size() - 1] == nums[0] + 1) return nums.size();
        return ret;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {3,2,2,3,2,1,3,3,3,-2,0,3,2,1,0,3,1,0,1,3,0,3,3};
    auto ans = s1.findLHS(nums);
    cout << ans << endl;
}
