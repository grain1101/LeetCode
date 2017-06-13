#include "leetcode.h"

// 561. Array Partition I
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for(int i = 0; i < nums.size(); i += 2){
            ret += nums[i];
        }
        return ret;
    }
};

int main() {
    Solution s1;
    //vector<int> nums = {48,66,61,46,94,75};
    vector<int> nums = {2,2,2};
    string s = "abcxyz123";
    vector<string> dict = {"abc","123"};
    s1.addBoldTag(s, dict);
    //cout << ans << endl;
}
