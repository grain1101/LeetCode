#include "leetcode.h"

class Solution {
public:
    // 300. Longest Increasing Subsequence
    int lengthOfLIS(vector<int>& nums) {
        vector<int> len(nums.size(), INT_MAX);
        for(auto d : nums) *lower_bound(len.begin(), len.end(), d) = d;
        return lower_bound(len.begin(), len.end(), INT_MAX) - len.begin();
    }
};

int main() {
    Solution s1;
    string secret = "1807";
    string guess = "7810";
    auto ans = s1.getHint(secret, guess);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
