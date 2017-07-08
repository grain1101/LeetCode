#include "leetcode.h"

/**
Mock Interview
[LeetCode] Closest Binary Search Tree Value
Tree Recursive
 */

class Solution {
public:
    // 270 	Closest Binary Search Tree Value
    int closestValue(TreeNode* root, double target) {
        int ret = root->val;
        while(root){
            if (root->val == target) return target;
            if (abs(root->val - target) <= abs(ret->val - target)) ret = root->val;
            ret = min(ret, abs(root->val - target));
            if (root->val < target) root = root->right;
            else root = root->left;
        }
        return ret;
    }
};

int main() {
    Solution s1;

    vector<int> nums1 = {4,3,2,3,5,2,1};
    vector<int> nums2 = {0,0,0,0};
    vector<int> nums3 = {2,-2,2,-2, 2, -2};
    vector<vector<int>> nums = {{3,3,3,3},{2,-2,2,-2, 2, -2}};
    vector<int> ks = {4,2};
    auto ans = s1.divideArray(nums[1], ks[1]);
    show(ans);
}
