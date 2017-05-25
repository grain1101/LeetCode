#include "leetcode.h"

// 394. Decode String
class Solution {
public:
    string decodeString(string s) {
        int len = 0;
        return dfs(len, s);
    }
    string dfs(int &idx, const string& s) {
        string ret;
        for(; idx < s.size(); idx++) {
            if (isdigit(s[idx])) {
                int j = idx;
                while(j < s.size() && isdigit(s[j])) j++;
                int c = stoi(s.substr(idx, j - idx));
                idx = j + 1;
                string nextret = dfs(idx, s);
                while(c--) {
                    ret += nextret;
                }
            } else if (isalpha(s[idx])){
                ret.push_back(s[idx]);
            } else {
                return ret;
            }
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
