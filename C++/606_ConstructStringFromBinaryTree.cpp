#include "leetcode.h"

// 606. Construct String from Binary Tree
class Solution {
public:
    string tree2str(TreeNode* t) {
        if (t == nullptr) return "";
        preOrder(t);
        return ret;
    }
private:
    string ret;
    void preOrder(TreeNode* t){
        if (t == nullptr) return;
        ret += to_string(t->val);

        if (t->left != nullptr) {
            ret += '(';
            preOrder(t->left);
            ret += ')';
        }
        if (t->left == nullptr && t->right != nullptr){
            ret += "()";
        }
        if (t->right != nullptr){
            ret += '(';
            preOrder(t->right);
            ret += ')';
        }
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,3,2,2,2};
    auto ans = s1.findUnsortedSubarray(nums);
    //showV(ans);
    cout << ans << endl;
}
