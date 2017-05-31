#include "leetcode.h"

// 448. Find All Numbers Disappeared in an Array
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++){
            int cur = nums[i];
            while(nums[cur - 1] != cur){
                int tmp = nums[cur - 1];
                nums[cur - 1] = cur;
                cur = tmp;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != i + 1) ret.push_back(i + 1);
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
