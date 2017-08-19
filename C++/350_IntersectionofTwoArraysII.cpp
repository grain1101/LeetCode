#include "leetcode.h"

// 350. Intersection of Two Arrays II
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> ret;
        for(auto n : nums1) dict[n]++;
        for(auto n : nums2){
            if (dict.find(n) != dict.end() && dict[n] > 0) {
                ret.push_back(n);
                dict[n]--;
            }
        }
        return ret;
    }
};

int main() {
    Solution s1;
    string s = "leetcode";
    vector<int> nums1 = {1,2,3,1,2,1};
    vector<int> nums2 = {1,1,1};
    int k = 2;
    auto ans = s1.intersect(nums1, nums2);
    showV(ans);
    //cout << ans << endl;
}
