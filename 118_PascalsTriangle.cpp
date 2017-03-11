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
    // 118. Pascal's Triangle
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows <= 0) return ans;
        ans.push_back({1});
        for(int i = 2; i <= numRows; i++){
            vector<int> path(i, 1);
            for(int j = 1; j < i - 1; j++){
                path[j] = ans[ans.size() - 1][j - 1] + ans[ans.size() - 1][j];
            }
            ans.push_back(path);
        }
        return ans;
    }
};


int main() {
    Solution s1;
    auto result = s1.generate(5);
    show(result);

}
