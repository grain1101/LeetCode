#include "leetcode.h"

class Solution {
public:
    // 331. Verify Preorder Serialization of a Binary Tree
    bool isValidSerialization_stack(string preorder) {
        vector<string> strs;
        strSplit(preorder, strs);
        //showV(strs);
        stack<string> st;
        for(int i = 0; i < strs.size(); i++){
            string cur = strs[i];
            while (cur == "#" && !st.empty() && st.top() == cur){
                st.pop();
                if (st.empty()) return false;
                st.pop();
            }
            st.push(cur);
        }
        return st.size() == 1 && st.top() == "#";
    }
    bool isValidSerialization(string preorder) {
        vector<string> strs;
        strSplit(preorder, strs);
        int diff = 1;
        for(auto n : strs){
            diff--;
            if (diff < 0) return false;
            if (n != "#") diff += 2;
        }
        return diff == 0;
    }
private:
    void strSplit(const string& s, vector<string>& strs){
        if (s.size() == 0) return;
        int j = 0;
        for(int i = 1; i <= s.size(); i++){
            if (s[i] == ',' || i == s.size()){
                strs.push_back(s.substr(j, i - j));
                j = i + 1;
            }
        }
    }
};

int main() {
    Solution s1;
    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    auto ans = s1.isValidSerialization(s);
    cout << ans << endl;
}
