#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <set>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t << " ";
        }
        cout << endl;
    }
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 105. Construct Binary Tree from Preorder and Inorder Traversal
    TreeNode* dfs(int pl, int pr, int il, int ir){
        if (pl > pr) return nullptr;
        TreeNode *root = new TreeNode(preorder[pl]);

        for(int i = 0; i < n; i++){
            if (inorder[i] == root->val) {
                int lsize = i - il;
                int rsize = ir - i;
                root->left = dfs(pl + 1, pl + lsize, il, i - 1);
                root->right = dfs(pr - rsize + 1 , pr, i + 1, ir);
                break;
            }
        }

        return root;
    }
    TreeNode* buildTree(vector<int>& _preorder, vector<int>& _inorder) {
        preorder = _preorder;
        inorder = _inorder;
        n = preorder.size();
        if (n == 0 || inorder.size() != n) return nullptr;
        return dfs(0, n - 1, 0, n - 1);

    }
private:
    int n;
    vector<int> preorder;
    vector<int> inorder;
};


int main() {
    Solution s1;

}
