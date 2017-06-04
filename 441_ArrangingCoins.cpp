#include "leetcode.h"

// 441. Arranging Coins
class Solution {
public:
    int arrangeCoins(int n) {
        return (int) (-1 + sqrt(8LL * n + 1)) / 2.0;
    }
};

int main() {
    Solution s1;
    int num = 28;
    auto ans = s1.checkPerfectNumber(num);
    cout << ans << endl;
}
