#include "leetcode.h"

// 476. Number Complement
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        //return ~mask & ~num;
        return ~mask ^ num;
    }
};


int main() {
    Solution s1;
    int n = 5;
    auto ans = s1.findComplement(n);
    //showV(ans);
    cout << ans << endl;
}
