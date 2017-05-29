#include "leetcode.h"

// 357. Count Numbers with Unique Digits
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n > 10) n=10;
        vector<int> f(11, 0);
        f[0] = 1;
        f[1] = 9;
        for(int i = 2; i <= 10; i++){
            f[i] = f[i - 1] * (11 - i);
        }
        int ret = 0;
        for(int i = 0; i <= n; i++){
            ret += f[i];
        }
        return ret;
    }
};



int main() {
    Solution s1;
    int n = 11;
    auto ans = s1.countNumbersWithUniqueDigits(n);
    //showV(ans);
    cout << ans << endl;
}
