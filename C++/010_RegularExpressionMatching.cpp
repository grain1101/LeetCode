#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 10. Regular Expression Matching
    // '.' Matches any single character.
    // '*' Matches zero or more of the preceding element.
    // Input: aa,a; aa,aa;
    // Output:false; true;

    // method 1: DP
    // 关键在于如何处理这个'*'号。
    //
    // 状态：和Mininum Edit Distance这类题目一样。
    // dp[i][j]表示s[0:i-1]是否能和p[0:j-1]匹配。
    //
    // 递推公式：由于只有p中会含有regular expression，所以以p[j-1]来进行分类。
    // p[j-1] != '.' && p[j-1] != '*'：dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1])
    // p[j-1] == '.'：dp[i][j] = dp[i-1][j-1]
    //
    // 而关键的难点在于 p[j-1] = '*'。由于星号可以匹配0，1，乃至多个p[j-2]。
    // 1. 匹配0个元素，即消去p[j-2]，此时p[0: j-1] = p[0: j-3]
    // dp[i][j] = dp[i][j-2]
    //
    // 2. 匹配1个元素，此时p[0: j-1] = p[0: j-2]
    // dp[i][j] = dp[i][j-1]
    //
    // 3. 匹配多个元素，此时p[0: j-1] = { p[0: j-2], p[j-2], ... , p[j-2] }
    // dp[i][j] = dp[i-1][j] && (p[j-2]=='.' || s[i-2]==p[j-2])

    // method 2: Two-pointer scan
    // http://articles.leetcode.com/regular-expression-matching

    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1,false));
        dp[0][0] = true;

        for(int i=0; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(p[j-1]!='.' && p[j-1]!='*') {
                    if(i>0 && s[i-1]==p[j-1] && dp[i-1][j-1])
                        dp[i][j] = true;
                }
                else if(p[j-1]=='.') {
                    if(i>0 && dp[i-1][j-1])
                        dp[i][j] = true;
                }
                else if(j>1) {  //'*' cannot be the 1st element
                    if(dp[i][j-1] || dp[i][j-2])  // match 0 or 1 preceding element
                        dp[i][j] = true;
                    else if(i>0 && (p[j-2]==s[i-1] || p[j-2]=='.') && dp[i-1][j]) // match multiple preceding elements
                        dp[i][j] = true;
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    // 1. Input test cases
    int num = 1001;
    string ss1 = "aa";
    string ss2 = "a";

    // 2. Run
    Solution s1;
    auto result = s1.isMatch(ss1, ss2);

    // 3. Compare output

    cout << result << endl;
    return 0;
}
