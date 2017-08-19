#include "leetcode.h"

// 459. Repeated Substring Pattern
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 1, j = 0, n = s.size();
        vector<int> dp(n + 1, 0);
        while(i < n){
            if (s[i] == s[j]) dp[++i] = ++j;
            else if (j == 0) i++;
            else j = dp[j];
        }
        return dp[n] && (dp[n] % (n - dp[n]) == 0);
    }
};

int main() {
    Solution s1;
    string s = "abcabc";
    auto ans = s1.repeatedSubstringPattern(s);
    cout << ans << endl;
    int i = 0, j = 0;
}
