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
    //94. Binary Tree Inorder Traversal
    void dfs(vector<int>& ans, TreeNode* root){
        if (root == nullptr) return;
        if (root->left) dfs(ans, root->left);
        ans.push_back(root->val);
        if (root->right) dfs(ans, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        dfs(ans, root);
        return ans;
    }
};




int main() {
    string s = "25525511135";
    Solution s1;
    auto result =  s1.restoreIpAddresses(s);
    for(auto r : result)
        cout << r << endl;
    cout << endl;
    //cout << result << endl;
}
