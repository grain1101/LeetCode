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
#include <limits>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t << " ";
        }
        cout << endl;
    }
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // 91. Decode Ways
    // DP (070 Climbling Stairs)
    int numDecodings(string s) {
        if (s == "") return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            // b = s[i - 2] * 10 + a
            int a = s[i - 1] - '0';
            if (a >= 1 && a <= 26)
                dp[i] += dp[i - 1];
            if (i > 1){
                int b = (s[i - 2] - '0') * 10 + a;
                if (b >= 10 && b <= 26)
                    dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};




int main() {
    Solution s1;
    auto result =  s1.numDecodings("123");
    cout << result << endl;
}
