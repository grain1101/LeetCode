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
    // 222. Count Complete Tree Nodes
    int countNodes(TreeNode* root) {
        // recursive
        if (root == nullptr) return 0;
        int lh = 0, rh = 0;
        TreeNode *l = root, *r = root;
        while(l){
            lh++;
            l = l->left;
        }
        while(r){
            rh++;
            r = r->right;
        }
        if (lh == rh){
            return (1 << lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int countNodes_BFS(TreeNode* root) {
        // BFS->TLE
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ret = 0;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            ret++;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return ret;
    }
};

int main() {
    Solution s1;
    TreeNode* root = new TreeNode(1);
    auto ans = s1.countNodes(root);
    cout << (1<<1) << endl;
    //cout << ans << endl;
    //show(ans);
    //showV(ans);
}
