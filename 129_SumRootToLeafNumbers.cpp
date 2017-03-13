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
void showV(auto& result){
    for(auto r : result)
        cout << r;
    cout << endl;
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

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    // 129. Sum Root to Leaf Numbers
    void dfs(TreeNode* root, int& ans, vector<int>& path){
        if (root->left == nullptr && root->right == nullptr){
            int cur = 0;
            for(int i = 0; i < path.size(); i++){
                cur = cur * 10 + path[i];
            }
            cur = cur * 10 + root->val;
            cout << cur << endl;
            ans += cur;
            return;
        }
        path.push_back(root->val);
        if (root->left) dfs(root->left, ans, path);
        if (root->right) dfs(root->right, ans, path);
        path.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = 0;
        vector<int> path;
        dfs(root, ans, path);
        return ans;
    }
};

int main() {
    Solution s1;
    vector<string> ss = {"hot","dot","dog","lot","log","cog"};
    //auto result = s1.findLadders("hit","cog",ss);
    vector<int> v = {4,2,2,-4,0,-2,4,-3,-4,-4,-5,1,4,-9,5,0,6,-8,-1,-3,6,5,-8,-1,-5,-1,2,-9,1};
    cout << Solution().longestConsecutive(v) << endl;
    //show(result);
}
