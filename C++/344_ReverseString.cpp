#include "leetcode.h"

// 344. Reverse String
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution s1;
    string s = "abc";
    auto ans = s1.reverseString(s);
    cout << ans << endl;
}
