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

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    // 116. Populating Next Right Pointers in Each Node
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return ;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(q.size()){
            int n = q.size();
            while(n--){
                TreeLinkNode *first = q.front();
                q.pop();
                first->next = n == 0 ? nullptr : q.front();
                if (first->left) q.push(first->left);
                if (first->right) q.push(first->right);
            }
        }
        return;
    }
};


int main() {
    Solution s1;

}
