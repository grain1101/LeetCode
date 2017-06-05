#include "leetcode.h"

// 551. Student Attendance Record I
class Solution {
public:
    bool checkRecord(string s) {
        int cntA = 0;
        int cntL = 0;
        for(auto c : s){
            if (c == 'A') cntA++;
            if (c != 'L') cntL = 0;
            else cntL++;
            if (cntL > 2 || cntA > 1) return false;
        }
        return true;
    }
};

int main() {
    Solution s1;
    string s = "abcdefg";
    int k = 2;
    auto ans = s1.reverseStr(s, k);
    cout << ans << endl;
}
