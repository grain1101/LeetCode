#include "leetcode.h"
class Solution {
public:
    // 258. Add Digits
    int addDigits(int num) {
        if (num == 0) return num;
        return num % 9 == 0 ? 9 : num % 9;
        //return num == 0 ? num : num % 9 == 0 ? 9 : num%9;
    }
};

int main() {
    Solution s1;
    auto ans = s1.addDigits(9);
    //cout << ans << endl;
    showV(ans);
    //show(ans);
    //showV(ans);
}
