#include "leetcode.h"

class Solution {
public:
    // 326. Power of Three
    bool isPowerOfThree(int n) {
        if (n > 1){
            while(n%3 == 0) n /= 3;
        }
        return n==1;
    }
};

int main() {
    Solution s1;
    auto ans = s1.isPowerOfThree(81);
    cout << ans << endl;
}
