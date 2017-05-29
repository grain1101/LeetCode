#include "leetcode.h"

// 321. Create Maximum Number
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        if (k == 0) return ret;
        for(int sz1 = 0; sz1 <= k; sz1++) {
            if (sz1 > nums1.size()) continue;
            int sz2 = k - sz1;
            if (sz2 > nums2.size()) continue;
            vector<int> tmp;
            calc(nums1, sz1, nums2, sz2, tmp);
            if (ret.size() == 0 || ret < tmp) ret = tmp;
        }
        return ret;
    }

    vector<int> calcOneArray(const vector<int>& v, int k) {
        // keep largest
        vector<int> ret;
        k = v.size() - k;
        for(auto i : v) {
            while(ret.size() && ret.back() < i && k > 0) {
                ret.pop_back();
                k--;
            }
            ret.push_back(i);
        }
        while(k--) ret.pop_back();
        return ret;
    }
    void calc(const vector<int>& a, int sz1, const vector<int>& b, int sz2, vector<int>& ret) {
        vector<int> nums1 = calcOneArray(a, sz1);
        vector<int> nums2 = calcOneArray(b, sz2);
        int idx1 = 0, idx2 = 0;
        // merge nums1 and nums2 to one
        // greedy
        while(idx1 < nums1.size() || idx2 < nums2.size()) {
            bool left = true;
            for(int k = 0; ;k++) {
                if (k + idx1 == nums1.size()) {
                    left = false;
                    break;
                } else if (k + idx2 == nums2.size()) {
                    left = true;
                    break;
                } else if (nums1[idx1 + k] != nums2[idx2 + k]) {
                    if (nums1[idx1 + k] > nums2[idx2 + k]) {
                        left = true;
                        break;
                    } else {
                        left = false;
                        break;
                    }
                }
            }
            if (left) ret.push_back(nums1[idx1++]);
            else ret.push_back(nums2[idx2++]);
        }
    }
};


int main() {
    Solution s1;
    vector<int> nums1 = {3, 4, 6, 5};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    int k = 5;
    auto ans = s1.maxNumber(nums1, nums2, k);
    showV(ans);
    //cout << ans << endl;
}
