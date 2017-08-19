#include "leetcode.h"

// 513. Find Bottom Left Tree Value
// BFS
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ret;
        while(!q.empty()){
            int n = q.size();
            ret = q.front()->val;
            while(n > 0){
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                n--;
            }
        }
        return ret;
    }
};


int main() {
    Solution2 s1;
    string s = "abab";
    auto ans = s1.repeatedSubstringPattern("abadabad");
    cout << ans << endl;

    int i = 0, j = 0;
}
