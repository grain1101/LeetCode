//654. Maximum Binary Tree
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        int maxV = nums[0], idx = 0;
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] > maxV) {
                maxV = nums[i];
                idx = i;
            }
        }
        TreeNode *root = new TreeNode(nums[idx]);
        vector<int> left(nums.begin(), nums.begin() + idx);
        vector<int> right(nums.begin() + idx + 1, nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};