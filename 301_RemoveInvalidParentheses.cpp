#include "leetcode.h"

class Solution {
public:
    // 301. Remove Invalid Parentheses
    vector<string> removeInvalidParentheses(string s) {
        int left_removed = 0, right_removed = 0;
        for(auto c : s){
            if (c == '(') left_removed++;
            else if (c == ')'){
                if (left_removed > 0) left_removed--;
                else right_removed++;
            }
        }
        unordered_set<string> ret;
        dfs(s, 0, left_removed, right_removed, 0, "", ret);
        return vector<string>(ret.begin(), ret.end());
    }
private:

    void dfs(string& s, int index, int left_removed, int right_removed, int paired, string path, unordered_set<string>& ret){

        if (index == s.size()){
            if ( left_removed == 0 && right_removed == 0 && paired == 0){
                ret.insert(path);
            }
            return;
        }
        char cur = s[index];
        // cout << index << " " << cur  << endl;
        if (cur != '(' && cur != ')')
            dfs(s, index + 1, left_removed, right_removed, paired, path + cur, ret);
        else {
            if (cur == '('){
                if (left_removed > 0){
                    dfs(s, index + 1, left_removed - 1, right_removed, paired, path, ret);
                }
                dfs(s, index + 1, left_removed, right_removed, paired + 1, path + cur, ret);
            }
            if (cur == ')'){
                if (right_removed > 0){
                    dfs(s, index + 1, left_removed, right_removed - 1, paired, path, ret);
                }
                if (paired > 0){
                    dfs(s, index + 1, left_removed, right_removed, paired - 1, path + cur, ret);
                }
            }
        }
    }
};

int main() {
    Solution s1;
    string s = "()())()";
    auto ans = s1.removeInvalidParentheses(s);
    //cout << ans << endl;
    showV(ans);
    //show(ans);
    //showV(ans);
}
