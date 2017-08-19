#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 22. Generate Parentheses
    // input: 3
    // output: {"((()))", "(()())", "(())()", "()(())", "()()()"}
    // Solution: DFS
    void dfs(vector<string>& result, int n, string path, int l, int r){
        if(l==n){
//            for(int i=0;i<n-r;i++){
//                path += ')';
//            }
            /// string::append
            path.append(n-r,')');
            result.push_back(path);
            return;
        }
        dfs(result, n, path+'(', l+1, r);
        if(l>r){
            dfs(result, n, path+')', l, r+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs(result, n, "", 0, 0);
        return result;
    }
};

int main()
{
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    string s = "()[[]{}";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(1);
    int n = 3;

    // 2. Run
    Solution s1;
    auto result = s1.generateParenthesis(n);
    // 3. Compare output

    for(auto n : result){
        for(auto num : n){
            cout << num << " ";
        }
        cout << endl;
    }
//    cout << result << endl;
    return 0;
}
