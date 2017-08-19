#include "leetcode.h"

// 538. Convert BST to Greater Tree
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        tmp = 0;
        dfs(root);
        return root;
    }
private:
    int tmp;
    void dfs(TreeNode* root){
        if (root == nullptr) return ;
        dfs(root->right);
        root->val += tmp;
        tmp = root->val;
        dfs(root->left);
    }
};


int main() {
    Solution2 s1;
    string s = "abab";
    auto ans = s1.repeatedSubstringPattern("abadabad");
    cout << ans << endl;

    int i = 0, j = 0;
}
