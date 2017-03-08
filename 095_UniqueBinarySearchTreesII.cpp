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
    // 95. Unique Binary Search Trees II
    // divide as two part(left, right), then splice together
    vector<TreeNode*> dfs(int l, int n){
        vector<TreeNode*> ans;
        if (l > n){
            ans.push_back(nullptr);
            return ans;
        }
        if (l == n){
            ans.push_back(new TreeNode(l));
            return ans;
        }
        vector<TreeNode*> left;
        vector<TreeNode*> right;
        for(int rt = l; rt <= n; rt++){
            left = dfs(l, rt - 1);
            right = dfs(rt + 1, n);
            for(auto lp : left){
                for(auto rp : right){
                    TreeNode *root = new TreeNode(rt);
                    root->left = lp;
                    root->right = rp;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) return {};
        return dfs(1, n);
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
