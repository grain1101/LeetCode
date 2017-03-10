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
    // 106. Construct Binary Tree from Inorder and Postorder Traversal
    TreeNode* dfs(int postl, int postr, int inl, int inr){
        if (postl > postr) return nullptr;
        TreeNode *root = new TreeNode(postorder[postr]);
        for(int i = inl; i <= inr; i++){
            if (inorder[i] == root->val){
                int lsize = i - inl;
                int rsize = inr - i;
                root->left = dfs(postl, postl + lsize - 1, inl, i - 1);
                root->right = dfs(postr - rsize, postr - 1, i + 1, inr);
                break;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& _inorder, vector<int>& _postorder) {
        inorder = _inorder;
        postorder = _postorder;
        n = inorder.size();
        if (n == 0 || n != postorder.size()) return nullptr;
        return dfs(0, n - 1, 0, n - 1);
    }
private:
    int n;
    vector<int> inorder;
    vector<int> postorder;
};


int main() {
    Solution s1;

}
