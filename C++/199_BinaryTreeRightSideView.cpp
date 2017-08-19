#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <set>
#include <string>
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
        cout << r << " ";
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

class Solution {
public:
    // 199. Binary Tree Right Side View
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() != 0){
            int n = q.size();
            ans.push_back(q.front()->val);
            while(n--){
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->right) q.push(tmp->right);
                if (tmp->left) q.push(tmp->left);
            }
        }
        return ans;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,4,5};
    TreeNode *root = nullptr;
    auto ans = s1.rightSideView(root);

   // cout << ans << endl;
}
