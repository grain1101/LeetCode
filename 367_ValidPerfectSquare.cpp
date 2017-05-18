#include "leetcode.h"

// 367. Valid Perfect Square
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int i = num;
        for(i = i / 2; i>= 0; i--){
            if (i * i == num) return true;
        }
        return false;
    }
};

int main() {
    Solution s1;
    auto ans = s1.isPerfectSquare(16);
    cout << ans << endl;
}
