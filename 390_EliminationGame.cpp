#include "leetcode.h"

// 390. Elimination Game
class Solution {
public:
    // Josephus problem.
    // n = 2^m + l; f(n) = 2*l + 1;
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
};


int main() {
    Solution s1;
    string s = "sd2[f2[e]g]i";
    auto ans = s1.decodeString(s);
    cout << ans << endl;
}
