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
    // 20. Valid Parentheses
    // input: "()[]{}"; "([)]"; "()"
    // output: true;false;true;
    // Solutions: Stack;
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
            else{
                if(st.size()==0) return false;
                if(s[i]==')'){
                    if(st.top()!='(') return false;
                    else st.pop();
                }
                if(s[i]==']'){
                    if(st.top()!='[') return false;
                    else st.pop();
                }
                if(s[i]=='}'){
                    if(st.top()!='{') return false;
                    else st.pop();
                }
            }
        }
        return st.empty();
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
    int n = 1;

    // 2. Run
    Solution s1;
    auto result = s1.isValid(s);
    // 3. Compare output

//    for(auto n : result){
//        for(auto num : n){
//            cout << num << " ";
//        }
//        cout << endl;
//    }
    cout << result << endl;
    return 0;
}
