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
    // 101. Symmetric Tree
    bool isSymmetric(TreeNode* root) {

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
