#include "leetcode.h"

// 437. Path Sum III
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        ret = 0;
        if (root == nullptr) return ret;
        preSum.clear();
        preSum[0]++;
        target = sum;
        dfs(root, 0);
        return ret;
    }
private:
    int ret;
    int target;
    unordered_map<int, int> preSum;
    void dfs(TreeNode* root, long long sum){
        if (root == nullptr) return;
        sum += root->val;
        ret += preSum[sum - target];
        preSum[sum]++;
        dfs(root->left, sum);
        dfs(root->right, sum);
        preSum[sum]--;
    }
};



int main() {
    Solution s1;
    string s = "Hello 2";
    auto ans = s1.countSegments(s);
    //showV(ans);
    cout << ans << endl;
}
