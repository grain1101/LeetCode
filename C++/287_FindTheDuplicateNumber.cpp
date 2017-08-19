#include "leetcode.h"

class Solution {
public:
    // 287. Find the Duplicate Number
    int findDuplicate(vector<int>& nums) {
        if (nums.size() < 2) return -1;
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {2,3,1,4,3};
    auto ans = s1.findDuplicate(nums);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
