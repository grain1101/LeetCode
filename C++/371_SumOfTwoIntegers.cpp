#include "leetcode.h"

// 371. Sum of Two Integers
class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a^b, (a&b)<<1);
    }
};

int main() {
    Solution s1;
    auto ans = s1.getSum(0,1);
    cout << ans << endl;
}
