// 653. Two Sum IV - Input is a BST
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        m.clear();
        dfs(root);
        for(auto it = m.begin(); it != m.end(); it++) {
            if (m.find(k - it->first) != m.end()) {
                if (k - it->first != it->first) return true;
                if (k - it->first == it->first && it->second > 1) return true;
                
            }
        }
        return false;
    }
    void dfs(TreeNode* root) {
        if (!root) return ;
        m[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
private:
    unordered_map<int, int> m;
};