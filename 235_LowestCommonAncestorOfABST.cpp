#include "leetcode.h"

class Solution {
public:
    // 235. Lowest Common Ancestor of a Binary Search Tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);
        if (p == root) return p;
        if (q == root) return q;
        if (q->val < root->val) return lowestCommonAncestor(root->left, p,q);
        if (p->val < root->val) return root;
        return lowestCommonAncestor(root->right, p,q);
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
