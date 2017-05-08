#include "leetcode.h"
bool isBadVersion(int version){
    return version >= 1 ;
}

class Solution {
public:
    // 283. Move Zeroes
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != 0) nums[j++] = nums[i];
        }
        for(j; j < nums.size(); j++){
            nums[j] = 0;
        }
    }
};


int main() {
    Solution s1;
    vector<int> nums = {0,1};
    s1.moveZeroes(nums);
    //cout << ans << endl;
    showV(nums);
    //show(ans);
    //showV(ans);
}
