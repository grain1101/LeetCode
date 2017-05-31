#include "leetcode.h"

// 506. Relative Ranks
typedef pair<int, int> PII;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<PII> m(nums.size());
        vector<string> ret(nums.size());
        for(int i = 0; i < nums.size(); i++){
            m[i].first = nums[i];
            m[i].second = i;
        }
        sort(m.begin(), m.end(), greater<PII>());
        for(int i = 0; i < m.size(); i++){
            if (i == 0) ret[m[i].second] = "Gold Medal";
            else if (i == 1) ret[m[i].second] = "Silver Medal";
            else if (i == 2) ret[m[i].second] = "Bronze Medal";
            else {
               ret[m[i].second] = to_string(i + 1);
            }
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
