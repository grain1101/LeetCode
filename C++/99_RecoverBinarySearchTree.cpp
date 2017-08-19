//99. Recover Binary Search Tree
class Solution {
public:
    void recoverTree(TreeNode* root) {
        first = nullptr;
        second = nullptr;
        TreeNode *prev = nullptr;
        dfs(root, prev);
        swap(first, second);
    }
private:
    TreeNode *first;
    TreeNode *second;
    void dfs(TreeNode *root, TreeNode *prev){
        if (root == nullptr) return;
        dfs(root->left);
        if (!prev && prev->val > root->val){
            if (first == nullptr)
                first = prev;
            second = root;
        } 
        prev = root;
        dfs(root->right);
    }
};