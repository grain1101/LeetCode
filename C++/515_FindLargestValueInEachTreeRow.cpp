#include "leetcode.h"

// 515. Find Largest Value in Each Tree Row
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        ret.clear();
        dfs(root, 0);
        return ret;
    }
private:
    vector<int> ret;
    void dfs(TreeNode* root, int level){
        if (root == nullptr) return ;
        if (ret.size() == level){
            ret.push_back(root->val);
        }else {
            ret[level] = max(ret[level], root->val);
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
};


int main() {
    Solution2 s1;
    string s = "abab";
    auto ans = s1.repeatedSubstringPattern("abadabad");
    cout << ans << endl;

    int i = 0, j = 0;
}
