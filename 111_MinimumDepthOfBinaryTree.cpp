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
    // 111. Minimum Depth of Binary Tree
    void dfs(TreeNode* root, int& minD, int level){
        if (root->left == nullptr && root->right == nullptr) {
            minD = min(minD, level);
            return;
        }
        if (root->left) dfs(root->left, minD, level + 1);
        if (root->right) dfs(root->right, minD, level + 1);
    }
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int minD = INT_MAX;
        dfs(root, minD, 1);
        return minD;
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
