#include "leetcode.h"

// 453. Minimum Moves to Equal Array Elements
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = INT_MAX;
        int ret = 0;
        for(int i = 0; i < nums.size(); i++){
            minNum = min(minNum, nums[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            ret += nums[i] - minNum;
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
