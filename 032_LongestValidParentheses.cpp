#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 32. Longest Valid Parentheses
    // Input:  ")()())";"()(())"; "(()(()()"
    // Output: 4; 6; 4
    int longestValidParentheses(string s) {
        stack<int> st;
        int result = 0;
        for(int i=0;i<s.size();i++){
            if (s[i] == '(') st.push(i);
            if (s[i] == ')') {
                if (st.size() != 0 && s[st.top()] == '(') {
                    st.pop();
                } else {
                    st.push(i);
                }
            }
        }
        if (st.size()==0) return s.size();
        int r = s.size();
        while(st.size()){
            int l = st.top(); st.pop();
            result = max(result, r-l-1);
            r=l;
        }
        result = max(result, r);
        return result;
    }
};

int main() {
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {4,3,1};
    string ss = "))))()";
    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(0);
    ListNode *p = head;
    int n = 3;
    vector<ListNode*> lists;

    // 2. Run
    Solution s1;
    auto result = s1.longestValidParentheses(ss);
    // 3. Compare output
//    for(auto i : result){
//        cout << i << " ";
//    }
//    cout << endl;
    cout << result << endl;
    return 0;
}
