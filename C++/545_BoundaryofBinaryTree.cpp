#include "leetcode.h"

typedef pair<int, int> PII;
class Solution {
public:
    // 545 Boundary of Binary Tree
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        ret.push_back(root->val);
        findLeftPath(root->left, ret);
        findLeaf(root, ret);
        findRightPath(root->right, ret);
//        cout << "leaf" << endl;        showV(leaf);
//        cout << "left" << endl;        showV(left);
//        cout << "right" << endl;       showV(right);
        return ret;
    }
    void findLeaf(TreeNode* root, vector<int>& ret){
        if(root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr){
            ret.push_back(root->val);
            return;
        }
        findLeaf(root->left, ret);
        findLeaf(root->right, ret);
    }
    void findLeftPath(TreeNode* root, vector<int>& ret){ // left and root
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return;
        ret.push_back(root->val);
        if (root->left) findLeftPath(root->left, ret);
        else findLeftPath(root->right, ret);
    }
    void findRightPath(TreeNode* root, vector<int>& ret){ // right
        if (root == nullptr || (!root->left && !root->right)) return;
        if (root->right) findRightPath(root->right, ret);
        else  findRightPath(root->left, ret);
        ret.push_back(root->val);
    }
};

int main() {
    Solution s1;
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(0);
    root1->right = new TreeNode(4);
    root1->right->right = new TreeNode(5);
    auto ans = s1.boundaryOfBinaryTree(root1);

//    TreeNode *root2 = new TreeNode(1);
//    root2->right = new TreeNode(2);
//    TreeNode* r = root2->right;
//    r->left = new TreeNode(3);
//    r->right = new TreeNode(4);
//    auto ans = s1.boundaryOfBinaryTree(root2);

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
//    auto ans = s1.boundaryOfBinaryTree(root3);

    showV(ans);
    //cout << ans << endl;
}
