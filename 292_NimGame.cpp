#include "leetcode.h"

class Solution {
public:
    // 292. Nim Game
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {2,3,1,4,3};
    string s = "e";
    string ss = "eukera";
    auto ans = s1.wordPattern(s,ss);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
