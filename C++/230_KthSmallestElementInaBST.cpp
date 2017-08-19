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
#include<list>
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    // 230. Kth Smallest Element in a BST
    int cnt = 0, ret = INT_MAX;
    void inOrderTraversal(TreeNode* root, int k){
        // dfs
        if (root == nullptr) return;
        inOrderTraversal(root->left, k);
        cnt++;
        if (cnt == k) {
            ret = root->val;
            return;
        };
        inOrderTraversal(root->right, k);
    }
    void inOrderTraversal1(TreeNode* root, int k){
        // recursive
        stack<TreeNode*> st;
        int cnt = 0, ret = INT_MAX;
        TreeNode *p = root;
        while(!st.empty() || p != nullptr){
            if (p){
                st.push(p);
                p = p->left;
            }
            else {
                TreeNode *node = st.top();
                st.pop();
                cnt++;
                if (cnt == k){
                    ret = node->val;
                    return;
                }
                p = node->right;
            }
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrderTraversal(root, k);
        return ret;
    }

};

int main() {
    Solution s1;
    TreeNode *root = new TreeNode(1);
    auto ans = s1.kthSmallest(root,1);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
