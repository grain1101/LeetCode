#include "leetcode.h"

class Solution {
public:
    // 319. Bulb Switcher
//    A light will be toggled only during the round of its factors,
//    e.g. number 6 light will be toggled at 1,2,3,6 and light 12 will be toggled at 1,2,3,4,6,12.
//    The final state of a light is on and off only depends on if the number of its factor is odd or even.
//    If odd, the light is on and if even the light is off. The number of one number's factor is odd if and only if it is a perfect square!
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int main() {
    Solution s1;
    auto ans = s1.maxProduct(words);
    cout << ans << endl;
//    showV(ans);
    //show(ans);
    //showV(ans);
}
