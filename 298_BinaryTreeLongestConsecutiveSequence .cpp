#include <unistd.h>
#include <cstdio>
#include <cassert>
#include "leetcode.h"
using namespace std;


class Solution {
public:
  // 298  Binary Tree Longest Consecutive Sequence
  int longestConsecutive(TreeNode* root) {
      int ret = 0;
      dfs(root, ret);
      return ret;
  }
private:
  int dfs(TreeNode* root, int& ret){
      if (root == nullptr) return 0;
      int left = dfs(root->left, ret);
      int right = dfs(root->right, ret);
      int cur = 1;
      if (root->left != nullptr && root->val + 1 == root->left->val)
          cur = max(cur, 1 + left);
      if (root->right != nullptr && root->val + 1 == root->right->val)
          cur = max(cur, 1 + right);
      ret = max(ret, cur);
      return cur;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> edge = {{0, 5, 2}, {1, 5, 7},
                              {0, 2, 1}, {1, 2, 4},
                              {0, 4, 3},
                              {0, 7, 6}, {1, 7, 8}};
  vector<TreeNode*> v = createBST(9, edge);
  for(int i = 1; i <= 8; i++) {
    auto ret = Solution().longestConsecutive(v[i]);
    cout << ret << ' '; cout << endl;
    //for(auto z : ret) cout << z << ' '; cout << endl;
  }
}
