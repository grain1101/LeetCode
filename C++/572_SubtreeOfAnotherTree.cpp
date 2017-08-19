#include "leetcode.h"
class Solution {
public:
    // 572. Subtree of Another Tree
    bool isSameTree(TreeNode* s, TreeNode* t){
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        return (s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};

int main() {
    Solution s1;
    vector<int> nums = {0,1,2,4};
    auto ans = s1.minDistance();
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
