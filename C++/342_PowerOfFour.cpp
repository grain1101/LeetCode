#include "leetcode.h"

// 342. Power of Four
class Solution {
public:
    bool isPowerOfFour(int n) {
        // 1. n is positive
        // 2. n is power of 2
        // 3. n binary form: "1" should only located at odd position.
        // 4. 0x55555555 each 5 is 4 bits. 5->0101
        return (n > 0) && ((n & (n - 1)) == 0) && ((n & 0x55555555) == n);
    }
};

int main() {
    Solution s1;
    int n = 16382;
    auto ans = s1.isPowerOfFour(n);
    cout << ans << endl;
}
