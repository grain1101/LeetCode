#include "leetcode.h"

// 404. Sum of Left Leaves
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int ret = 0;
        if (root->left != nullptr){
            if (root->left->left == nullptr && root->left->right == nullptr)
                ret += root->left->val;
            else ret += sumOfLeftLeaves(root->left);
        }
        ret += sumOfLeftLeaves(root->right);
        return ret;
    }
};

int main() {
    Solution s1;
    string s = "ae";
    string t = "aea";
    auto ans = s1.readBinaryWatch(2);
    showV(ans);
}
