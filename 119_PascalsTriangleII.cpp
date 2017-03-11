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
    // 119. Pascal's Triangle II
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) return {};
        vector<int> before = {1};
        for(int i = 2; i <= rowIndex + 1; i++){
            vector<int> ans(i, 1);
            for(int j  = 1; j < i - 1; j++){
                ans[j] = before[j - 1] + before[j];
            }
            before = ans;
        }
        return before;
    }
};


int main() {
    Solution s1;
    auto result = s1.getRow(3);
    for(auto r : result)
        cout << r << " ";
    cout << endl;
}
