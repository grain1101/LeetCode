#include "leetcode.h"
class Solution {
public:
    // 263. Ugly Number
    bool isUgly(int num) {
        for(int i = 2; i < 6 && num; i++){
            while(num % i == 0){
                num /= i;
            }
        }
        return num == 1;
    }
};

int main() {
    Solution s1;
    auto ans = s1.isUgly(31);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
