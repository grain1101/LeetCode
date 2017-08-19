#include "leetcode.h"

// 401. Binary Watch
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        ret.clear();
        for(int h = 0; h < 12; h++) {
            for(int m = 0; m < 60; m++) {
                if (__builtin_popcount(h) + __builtin_popcount(m) != num) continue;
                string minute = to_string(m);
                if (minute.size() < 2) minute = "0" + minute;
                ret.push_back(to_string(h) + ":" + minute);
            }
        }
        return ret;
    }
private:
    vector<string> ret;
};

int main() {
    Solution s1;
    int num = -3;
    auto ans = s1.toHex(num);
    cout << ans << endl;
}
