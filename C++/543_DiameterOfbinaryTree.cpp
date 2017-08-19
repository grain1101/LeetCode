#include "leetcode.h"

// 543. Diameter of Binary Tree
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        ret = 0;
        getHeight(root);
        return ret - 1;
    }
private:
    int ret;
    int getHeight(TreeNode* root){
        if (root == nullptr) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        ret = max(ret, left + right + 1);
        return max(left, right) + 1;
    }
};

int main() {
    Solution s1;
    string s = "abcdefg";
    int k = 2;
    auto ans = s1.reverseStr(s, k);
    cout << ans << endl;
}
