#include "leetcode.h"

// 520. Detect Capital
class Solution {
public:
    bool detectCapitalUse(string word) {
        int i = 0, cnt = 0;
        for(; i < word.size(); i++){
            if (isCapital(word[i])) cnt++;
        }
        return (cnt == word.size() || cnt == 0 || (cnt == 1 && isCapital(word[0])));
    }
private:
    // A: 65, Z: 90
    // a: 97, z: 122
    // if 'Z' - c >= 0, c is capital;
    bool isCapital(const char& c){
        return c >='A' && c <='Z';
    }
};


int main() {
    Solution s1;
    auto ans = s1.hammingDistance(1,4);
    //showV(ans);
    cout << ans << endl;
}
