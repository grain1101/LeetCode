#include "leetcode.h"

// 392. Is Subsequence
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for(int i = 0; i < t.size(); i++){
            if (j < s.size() && t[i] == s[j]) j++;
        }
        return j == s.size();
    }
};


int main() {
    Solution s1;
    string s = "sd2[f2[e]g]i";
    auto ans = s1.decodeString(s);
    cout << ans << endl;
}
