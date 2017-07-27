#include "leetcode.h"
/**
163_MissingRanges.cpp
Given a sorted integer array where the range of elements are [0, 99] inclusive, return its missing ranges.
For example, given [0, 1, 3, 50, 75], return ["2", "4->49", "51->74", "76->99"]
http://www.cnblogs.com/grandyang/p/5184890.html

Similar ro: 228 Summary Ranges
*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        int l = lower;
        for(int i = 0; i <= nums.size(); i++){
            int r = (i < nums.size() && nums[i] <= upper) ? nums[i] : upper + 1;
            if (l == r) l++;
            else if (r > l){
                string tmp = (r - l == 1) ? to_string(l) : to_string(l) + "->" + to_string(r - 1);
                ret.push_back(tmp);
                l = r + 1;
            }
        }
        return ret;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        // For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
        vector<string> ret;
        int i = 0, n = nums.size();
        while(i < n){
            int j = 1;
            while(i + j < n && nums[i + j] == nums[i] + j) j++;
            string tmp = (j <= 1) ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]);
            i += j;
            ret.push_back(tmp);
        }
        return ret;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {0, 1, 3, 50, 75,120};
    auto ans = s1.findMissingRanges(nums, 0, 99);
    showV(ans);
    //cout << ans << endl;
}
