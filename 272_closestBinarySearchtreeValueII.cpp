#include "leetcode.h"
/**
[LeetCode] Closest Binary Search Tree Value II
Use two stacks to find predecessor and successor.
 */

 /*
          5
         / \
        /   \
       2     7
      / \   / \
     1  4  6   8
       /
      3
*/

TreeNode* createBST(int n, const vector<vector<int>>& edge) {
  vector<TreeNode*> v;
  for(int i = 0; i < n; i++) {
    v.push_back(new TreeNode(i));
  }

  for(auto& t : edge) {
    if (t[0] == 0) {
      v[t[1]]->left = v[t[2]];
    } else {
      v[t[1]]->right = v[t[2]];
    }
  }
  return v[5];
}

class Solution {
public:
    // 272 	Closest Binary Search Tree Value II
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // find lowerbound p;
        vector<int> ret;
        stack<TreeNode*> pre;
        stack<TreeNode*> suc;
        TreeNode *p = nullptr;
        while(root){
            if (root->val <= target){
                pre.push(root);
                root = root->right;
            }
            else{
                suc.push(root);
                root = root->left;
            }
        }
        while(ret.size() < k){
            // getPredecessor, getSuccessor
            if (!pre.empty() && (suc.empty() || !suc.empty() && fabs(pre.top()->val - target) <= fabs(suc.top()->val - target))){
                ret.push_back(pre.top()->val);
                getPredecessor(pre);
            }else {
                ret.push_back(suc.top()->val);
                getSuccessor(suc);
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
    void getPredecessor(stack<TreeNode*>& pre){
        TreeNode* p = pre.top();
        pre.pop();
        p = p->left;
        while(p){
            pre.push(p);
            p = p->right;
        }
    }
    void getSuccessor(stack<TreeNode*>& suc){
        TreeNode *p = suc.top();
        suc.pop();
        p = p->right;
        while(p){
            suc.push(p);
            p = p->left;
        }
    }
};

int main() {
  vector<vector<int>> edge = {{0, 5, 2}, {1, 5, 7},
                              {0, 2, 1}, {1, 2, 4},
                              {0, 4, 3},
                              {0, 7, 6}, {1, 7, 8}};
  TreeNode* tree1 = createBST(9, edge);
//    showV(Solution().closestKValues(tree1, 4.9, 3));
  assert(Solution().closestKValues(tree1, 0.0, 3) == vector<int>({1, 2, 3}));
  assert(Solution().closestKValues(tree1, 4.9, 3) == vector<int>({4, 5, 6}));
  assert(Solution().closestKValues(tree1, 14.9, 3) == vector<int>({6, 7, 8}));
  assert(Solution().closestKValues(tree1, 0.0, 8) == vector<int>({1, 2, 3, 4, 5, 6, 7, 8}));
  assert(Solution().closestKValues(tree1, 4.4, 8) == vector<int>({1, 2, 3, 4, 5, 6, 7, 8}));
  assert(Solution().closestKValues(tree1, 10.0, 8) == vector<int>({1, 2, 3, 4, 5, 6, 7, 8}));
  assert(Solution().closestKValues(tree1, 4.4, 7) == vector<int>({1, 2, 3, 4, 5, 6, 7}));
  assert(Solution().closestKValues(tree1, 5.6, 1) == vector<int>({6}));
  assert(Solution().closestKValues(tree1, 1, 1) == vector<int>({1}));
}
