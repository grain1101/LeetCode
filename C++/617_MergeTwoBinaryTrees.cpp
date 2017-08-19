#include "leetcode.h"

// 617. Merge Two Binary Trees
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* root;
        root = dfs(t1, t2);
        return root;
    }
    TreeNode* dfs(TreeNode* t1, TreeNode* t2){
        if (t1 == nullptr && t2 == nullptr) return t1;
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        int tmp = t1->val + t2->val;
        TreeNode* root = new TreeNode(tmp);
        root->left = dfs(t1->left, t2->left);
        root->right = dfs(t1->right, t2->right);
        return root;
    }
};


int main() {
    Solution s1;
    string s = "abab";
//    auto ans = s1.repeatedSubstringPattern("abadabad");
//    cout << ans << endl;
    int main = 1;
    int i = 0, j = 0;
}
