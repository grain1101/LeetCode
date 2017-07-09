#include "leetcode.h"

typedef pair<int, int> PII;
class Solution {
public:
    // 549 Binary Tree Longest Consecutive Sequence II
    int longestConsecutive(TreeNode* root) {
        int ret = 0;
        dfs(root, ret);
        return ret;
    }
    // PII first: root = 3, root->child = 4;  second:root = 3, root->child = 2;
    PII dfs(TreeNode *root, int& ret){
        if (root == nullptr) return {0,0};
        PII cur = {1,1};
        PII left = dfs(root->left, ret);
        PII right = dfs(root->right, ret);
        if (root->left) {
            if (root->left->val + 1 == root->val) cur.second = max(cur.second, left.second + 1);
            if (root->left->val - 1 == root->val) cur.first = max(cur.first, left.first + 1);
        }
        if (root->right) {
            if (root->right->val + 1 == root->val) cur.second = max(cur.second, right.second + 1);
            if (root->right->val - 1 == root->val) cur.first = max(cur.first, right.first + 1);
        }
        ret = max(ret, cur.first + cur.second - 1);
        return cur;
    }
};

int main() {
    Solution s1;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(0);
    root->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    auto ans = s1.longestConsecutive(root);
    cout << ans << endl;
}
