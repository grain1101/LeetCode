#include "leetcode.h"

// 409. Longest Palindrome
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> chars(26*2);
        for(int i = 0; i < s.size(); i++){
            if (s[i] >= 'a' && s[i] <= 'z') chars[s[i]-'a']++;
            else chars[s[i]-'A'+26]++;
        }
        int ret = 0;
        int flag = 0;
        for(int i = 0; i < s.size(); i++){
            if (chars[i] % 2 == 0) ret += chars[i];
            else {
                flag = 1;
                ret += chars[i] - 1;
            }
        }
        return ret + flag;
    }
};

int main() {
    Solution s1;
    int num = -3;
    auto ans = s1.toHex(num);
    cout << ans << endl;
}
