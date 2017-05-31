#include "leetcode.h"

// 530. Minimum Absolute Difference in BST
// this is a BST; so in-order traversal is already sorted.
// So, we just need to subtract the previous element from the current one, and keep track of the minimum
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ret = INT_MAX;
        TreeNode* prev = nullptr;
        inOrderTraversal(root, prev, ret);
        return ret;
    }
private:
    void inOrderTraversal(TreeNode* root, TreeNode*& prev, int& ret){
        if (root->left) inOrderTraversal(root->left, prev, ret);
        if (prev != nullptr) ret = min(ret, abs(root->val - prev->val));
        prev = root;
        if (root->right) inOrderTraversal(root->right, prev, ret);
    }
};


int main() {
    Solution s1;
    auto ans = s1.hammingDistance(1,4);
    //showV(ans);
    cout << ans << endl;
}
