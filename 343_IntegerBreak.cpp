#include "leetcode.h"

// 343. Integer Break
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        return 3 * max(n - 3, integerBreak(n - 3));
    }
};

int main() {
    Solution s1;
    int n = 20;
    auto ans = s1.integerBreak(n);
    cout << ans << endl;
}
