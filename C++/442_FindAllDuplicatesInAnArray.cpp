#include "leetcode.h"

// 442. Find All Duplicates in an Array
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++){
            while (nums[nums[i] - 1] != nums[i]) swap(nums[nums[i] - 1], nums[i]);
        }

        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != i + 1) ret.push_back(nums[i]);
        }
        return ret;
    }
};


int main() {
    Solution s1;
    auto ans = s1.hammingDistance(1,4);
    //showV(ans);
    cout << ans << endl;
}
