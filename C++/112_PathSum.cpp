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
    // 112. Path Sum
    void dfs(TreeNode* root, int sum, int cur, bool& flag){
        if (cur == sum && root->left == nullptr && root->right == nullptr) {
            flag = true;
            return;
        }
        if (root->left) dfs(root->left, sum, cur + root->left->val, flag);
        if (root->right) dfs(root->right, sum, cur + root->right->val, flag);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        bool flag = false;
        dfs(root, sum, root->val, flag);
        return flag;
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
