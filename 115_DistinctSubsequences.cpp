// 115. Distinct Subsequences
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return 0;
        int ret = 0;
        //if (s == t) return 1;
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int i = 0; i < s.size() + 1; i++) dp[i][0] = 1;
        for(int i = 1; i < s.size() + 1; i++) {
            for(int j = 1; j < t.size() + 1; j++) {
                if (i < j) continue;
                dp[i][j] = dp[i - 1][j] + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[s.size()][t.size()];
    }
};