#include "leetcode.h"

// 409. Longest Palindrome
class Solution {
public:
     int longestPalindrome(string s) {
        int ret = 0, mid = 0;
        unordered_map<char, int> m;
        for(auto c : s) m[c]++;
        for(auto it = m.begin(); it!=m.end(); it++) {
            ret += it->second;
            if (it->second % 2) {
                ret -= 1;
                mid = 1;
            }
        }
        return ret + mid;
     }
};

int main() {
    Solution s1;
    int num = -3;
    auto ans = s1.toHex(num);
    cout << ans << endl;
}
