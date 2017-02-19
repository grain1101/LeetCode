#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 44. Wildcard Matching
    // 10. Regular Expression Matching
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // dp[i][j] = s[0 : i-1] match p[0 : j-1]
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        vector<bool> v(m);
        v[0] = true;
        for(int i = 0; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if (i > 0 && p[j - 1] != '?' && p[j - 1] != '*') {
                    dp[i][j] = (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
                } else if (i > 0 && p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*'){
                    dp[i][j] = v[j-1];
                }
                if (dp[i][j]) v[j] = true;
            }
        }
        return dp[m][n];
    }
};

int main() {
    // 1. Input test cases
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int n = 8;
    string a = "123";
    string b = "456";
    // 2. Run
    Solution s1;
    auto result = s1.multiply(a,b);

    // 3. Compare output
//    for(auto i : result){
//        for(auto t : i)
//            cout << t << " ";
//        cout << endl;
//    }

    cout << result << endl;
    return 0;
}
