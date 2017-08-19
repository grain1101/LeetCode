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
    // 113. Path Sum II
    void dfs(vector<vector<int>>& ans, vector<int>& path, TreeNode* root, int sum, int cur){
        if (root == nullptr) return;
        path.push_back(root->val);
        cur += root->val;
        if (cur == sum && root->left == nullptr && root->right == nullptr){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        dfs(ans, path, root->left, sum, cur);
        dfs(ans, path, root->right, sum, cur);
        cur -= root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        vector<int> path;
        dfs(ans, path, root, sum, 0);
        return ans;
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
