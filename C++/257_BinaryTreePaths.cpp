#include "leetcode.h"
class Solution {
public:
    // 257. Binary Tree Paths
    void dfs(vector<int>& path, TreeNode* root){
       if (root == nullptr) return;
        path.push_back(root->val);
        dfs(path, root->left);
        dfs(path, root->right);
        if (!root->left && !root->right) ans.push_back(path);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        vector<int> path;
        dfs(path, root);
        for(int i = 0; i < ans.size(); i++){
            string s;
            for(int j = 0; j < ans[i].size(); j++){
                if (j == 0) s += to_string(ans[i][j]);
                else s += "->" + to_string(ans[i][j]);
            }
            ret.push_back(s);
        }
        return ret;
    }
private:
    vector<vector<int>> ans;
};

int main() {
    Solution s1;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    auto ans = s1.binaryTreePaths(root);
    //cout << ans << endl;
    showV(ans);
    //show(ans);
    //showV(ans);
}
