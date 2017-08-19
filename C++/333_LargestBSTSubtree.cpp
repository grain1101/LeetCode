#include "leetcode.h"

/*
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:

    10
    / \
   5  15
  / \   \
 1   8   7
The Largest BST Subtree in this case is the highlighted one.
The return value is the subtree's size, which is 3.
*/

struct BSTInfo{
    bool isBST = false;
    int minV = INT_MAX;
    int maxV = INT_MIN;
    int cnt = 0;
};

class Solution {
public:
    // 333 Largest BST Subtree
    int largestBSTSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    BSTInfo dfs(TreeNode* root, int& ans){
        BSTInfo ret;
        if (root == nullptr) {
            ret.isBST = true;
            return ret;
        }
        BSTInfo left = dfs(root->left, ans);
        BSTInfo right = dfs(root->right, ans);

        if (!left.isBST || !right.isBST) return ret;
        bool lBST = (root->left == nullptr) || (root->left && left.maxV <= root->val);
        bool rBST = (root->right == nullptr) || (root->right && right.minV >= root->val);

        if (lBST && rBST){
            ret.cnt = left.cnt + right.cnt + 1;
            ret.isBST = true;
            ret.maxV = root->right ? right.maxV : root->val;
            ret.minV = root->left ? left.minV : root->val;
            ans = max(ans, ret.cnt);
            return ret;
        }
        return ret;
    }
};

int main() {
    Solution s1;

//    TreeNode *root1 = new TreeNode(2);
//    root1->left = new TreeNode(0);
//    root1->right = new TreeNode(4);
//    root1->right->right = new TreeNode(5);
//    auto ans = s1.boundaryOfBinaryTree(root1);

    TreeNode *root2 = new TreeNode(10);
     root2->left = new TreeNode(5);
    root2->right = new TreeNode(15);
    TreeNode* r = root2->left;
    r->left = new TreeNode(1);
    r->right = new TreeNode(8);
    root2->right->right = new TreeNode(7);
    auto ans = s1.largestBSTSubtree(root2);

//    TreeNode *root3 = new TreeNode(1);
//    root3->left = new TreeNode(2);
//    root3->right = new TreeNode(3);
//    TreeNode* l = root3->left;
//    TreeNode* r = root3->right;
//    l->left = new TreeNode(4);
//    l->right = new TreeNode(5);
//    r->left = new TreeNode(6);
//    l->right->left = new TreeNode(7);
//    l->right->right = new TreeNode(8);
//    r->left->left = new TreeNode(9);
//    r->left->right = new TreeNode(10);
//    auto ans = s1.largestBSTSubtree(root3);

   // showV(ans);
    cout << ans << endl;
}
