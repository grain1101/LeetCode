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
    // 98. Validate Binary Search Tree
    bool dfs(TreeNode*& root, int lMax, int rMin){
        if (root->left == nullptr && root->right == nullptr) return true;
        lMax = max(lMax, root->left->val);
        rMin = min(rMin, root->right->val);
        if (root->val < root->right->val && root->val < rMin &&
            root->val > root->left->val && root->val > lMax) return true;
        return dfs(root->left, lMax, rMin) && dfs(root->right, lMax, rMin);
    }
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        return dfs(root, root->val, root->val);
    }
};




int main() {
    Solution s1;
    string str1 = "aabcc";
    string str2 = "dbbca";
    string str3 = "aadbbcbcac";
    auto result = s1.isInterleave(str1, str2, str3);
    cout << result << endl;
}
