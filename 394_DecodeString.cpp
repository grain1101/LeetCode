#include "leetcode.h"

// 394. Decode String
class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;
        string ret;
        for(int i = 0; i < s.size(); i++){
            if (isdigit(s[i])){
                int j = i;
                while(j < s.size() && isdigit(s[j])) j++;
                int n = 0;
                for(int k = i; k < j; k++){
                    n = n * 10 + s[k] - '0';
                }
                nums.push(n);
                i = j - 1;
            } else {
                if (s[i] == '[') {
                    continue;
                }
                if (isalpha(s[i])) {
                    int j = i;
                    while(j < s.size() && isalpha(s[j])) j++;
                    string cur = s.substr(i, j - i);
                    if (nums.size() == strs.size() && nums.size() != 0){
                        string top = strs.empty() ? "" : strs.top();
                        if (!strs.empty()) strs.pop();
                        strs.push(top + cur);
                    }
                    else if (nums.empty() && strs.empty()) ret += cur;
                    else strs.push(cur);
                    i = j - 1;
                }
                if (s[i] == ']'){
                    int n = nums.empty() ? 0 : nums.top();
                    if (!nums.empty()) nums.pop();
                    string str = strs.empty() ? "" : strs.top();
                    if (!strs.empty()) strs.pop();
                    string tmp= "";
                    for(int i = 0; i < n; i++){
                        tmp += str;
                    }

                    if (!strs.empty() || !nums.empty()){
                        string before = strs.empty() ? "" : strs.top();
                        if (!strs.empty()) strs.pop();
                        before += tmp;
                        strs.push(before);
                    }else {
                        ret += tmp;
                    }
                }
            }
        }
        while(!strs.empty()){
            ret += strs.top();
            strs.pop();
        }
        return ret;
    }
};


int main() {
    Solution s1;
    string s = "sd2[f2[e]g]i";
    auto ans = s1.decodeString(s);
    cout << ans << endl;
}
