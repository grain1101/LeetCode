#include "leetcode.h"
/*
DP
这道题的本质相当于在一列数组中取出一个或多个不相邻数，使其和最大。
*/ 

class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() <= 1) return num.empty() ? 0 : num[0];
        vector<int> dp = {num[0], max(num[0], num[1])};
        for (int i = 2; i < num.size(); ++i) {
            dp.push_back(max(num[i] + dp[i - 2], dp[i - 1]));
        }
        return dp.back();
    }
};

class Solution2 {
public:
    int rob(vector<int> &num) {
        int a = 0, b = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (i % 2 == 0) {
                a += num[i];
                a = max(a, b);
            } else {
                b += num[i];
                b = max(a, b);
            }
        }
        return max(a, b);
    }
};

class Solution3 {
public:
    int rob(vector<int> &nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int m = a, n = b;
            a = n + nums[i];
            b = max(m, n);
        }
        return max(a, b);
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,4,5};
    uint32_t n = 7;
    auto ans = s1.hammingWeight(n);
    cout << ans << endl;
}
