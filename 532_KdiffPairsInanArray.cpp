#include "leetcode.h"

// 532. K-diff Pairs in an Array
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int ret = 0;
        unordered_map<int, int> cnt;
        for(auto n : nums){
            cnt[n]++;
        }
        for(auto it = cnt.begin(); it != cnt.end(); it++){

            if (k == 0 && it->second > 1) ret++,cout << it->first << " " << it->second << endl;
            else if (k > 0 && cnt.find(it->first + k) != cnt.end()) ret++, cout << it->first << " " << it->second << endl;
        }
        return ret;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {3,1,4,1,5};
    auto ans = s1.findPairs(nums, 0);
    //showV(ans);
    cout << ans << endl;
}
