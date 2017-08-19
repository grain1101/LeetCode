#include "leetcode.h"

// 485. Max Consecutive Ones
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < nums.size(); i++){
            int tmp = 0;
            while(i < nums.size() && nums[i] == 1) tmp++, i++;
            ret = max(ret, tmp);
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
