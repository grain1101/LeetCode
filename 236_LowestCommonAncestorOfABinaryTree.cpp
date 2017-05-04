#include "leetcode.h"
class Solution {
public:
    // 236. Lowest Common Ancestor of a Binary Tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left){
            return right ? root : left;
        } else return right;
        // return !left ? right : !right ? left : root;
    }
};


int main() {
    Solution s1;
    int n = 3;
    auto ans = s1.isPalindrome(nullptr);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
