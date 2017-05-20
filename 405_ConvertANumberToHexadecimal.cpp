#include "leetcode.h"

// 405. Convert a Number to Hexadecimal
class Solution {
public:
    const string Hex = "0123456789abcdef";
    string toHex(int num) {
        if (num == 0) return "0";
        string ret;
        for(int i = 0; i < 8 && num; i++){
            ret.push_back(Hex[num & 0xf]);
            num = num >> 4;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    Solution s1;
    int num = -3;
    auto ans = s1.toHex(num);
    cout << ans << endl;
}
