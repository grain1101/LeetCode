#include "leetcode.h"

// 563. Binary Tree Tilt
class Solution {
public:
    int findTilt(TreeNode* root) {
        ret = 0;
        getSum(root);
        return ret;
    }
private:
    int ret;
    int getSum(TreeNode* root){
        if (root == nullptr) return 0;
        int l = getSum(root->left);
        int r = getSum(root->right);
        ret += abs(l - r);
        return root->val + l + r;
    }
};


int main() {
    Solution s1;
    auto ans = s1.hammingDistance(1,4);
    //showV(ans);
    cout << ans << endl;
}
