#include "leetcode.h"

// 504. Base 7
class Solution {
public:
    string convertToBase7(int num) {
        string ret;
        int x = abs(num);
        if (x == 0) return "0";
        while(x){
            ret = to_string(x % 7) + ret;
            x = x / 7;
        }
        return (num < 0 ? "-" : "") + ret;
    }
};

int main() {
    Solution s1;
    auto ans = s1.convertToBase7(-7);
    //showV(ans);
    cout << ans << endl;
}
