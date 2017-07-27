#include "leetcode.h"
/*
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
        4
       /
      1
     /
    2
   /
  3
 Maximum amount of money the thief can rob =4 + 3 = 7 
*/
class Solution {
public:
    // 337. House Robber III
    int rob(TreeNode* root) {
        return rob_dp_helper(root, mapping);
    }
private:
    unordered_map<TreeNode*, int> mapping;
    int rob_dp_helper(TreeNode* root, unordered_map<TreeNode*, int>& mapping){
        // memory search
        if (root == nullptr) return 0;
        if (mapping.find(root) != mapping.end()) return mapping[root];
        int val = 0;
        if (root->left != nullptr) val += rob_dp_helper(root->left->left, mapping) + rob_dp_helper(root->left->right, mapping);
        if (root->right != nullptr) val += rob_dp_helper(root->right->left, mapping) + rob_dp_helper(root->right->right, mapping);
        int ret = max(val + root->val, rob_dp_helper(root->left, mapping) + rob_dp_helper(root->right, mapping));
        mapping[root] = ret;
        return ret;
    }

    // int rob_naive(TreeNode* root) {
    //     if (root == nullptr) return 0;
    //     int val = 0;
    //     if (!root->left){
    //         val += rob_naive(root->left->left) + rob_naive(root->left->right);
    //     }
    //     if (!root->right){
    //         val += rob_naive(root->right->left) + rob_naive(root->right->left);
    //     }
    //     return max(val + root->val, rob_naive(root->left) + rob_naive(root->right));
    // }
};

int main() {
    Solution s1;
    vector<int> nums = {2,3,1,4, 5};
    auto ans = s1.increasingTriplet(nums);
    cout << ans << endl;
}
