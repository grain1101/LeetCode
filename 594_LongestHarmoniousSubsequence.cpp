#include "leetcode.h"

// 594. Longest Harmonious Subsequence
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        int ret = 0;
        for(auto n : nums){
            m[n]++;
            if (m.find(n - 1) != m.end()){
                ret = max(ret, m[n - 1] + m[n]);
            }
            if (m.find(n + 1) != m.end()){
                ret = max(ret, m[n + 1] + m[n]);
            }
        }
        return ret;
    }
};

int main() {
    Solution s1;
    string s = "abcdefg";
    int k = 2;
    auto ans = s1.reverseStr(s, k);
    cout << ans << endl;
}
