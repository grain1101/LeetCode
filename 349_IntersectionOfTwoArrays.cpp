#include "leetcode.h"

// 349. Intersection of Two Arrays
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num(nums1.begin(), nums1.end());
        vector<int> ret;
        for(auto n : nums2){
            if (num.find(n) != num.end()){
                ret.push_back(n);
                num.erase(n);
            }
        }
        return ret;
    }
};

int main() {
    Solution s1;
    string s = "leetcode";
    vector<int> nums1 = {1,2,3,1,2,1};
    vector<int> nums2 = {0};
    int k = 2;
    auto ans = s1.intersection(nums1, nums2);
    showV(ans);
    //cout << ans << endl;
}
