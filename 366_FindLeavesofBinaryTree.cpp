//366_Find Leaves of Binary Tree
// falling leaves
class Solution {
public:
    // post order recursive; O(nlogn)
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<set<TreeNode*>> ret;
        dfs(root, ret);
        return ret;
    }
    int dfs(TreeNode* root, vector<set<TreeNode*>>& ret) {
        if (!root) return -1;
        int level = max(dfs(root->left, ret), dfs(root->right, ret)) + 1;
        if (ret.size() <= level) ret.push_back({});
        ret[level].push_back(root);    
        return level;
    }
};