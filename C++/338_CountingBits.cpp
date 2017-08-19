#include "leetcode.h"

class Solution {
public:
    // 338. Counting Bits
    vector<int> countBits(int num) {
        vector<int> ret(num + 1, 0);
        for(int i = 1; i <= num; i++){
            ret[i] = ret[i&(i-1)] + 1;
        }
        return ret;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {2,3,1,4, 5};
    int n = 7;
    auto ans = s1.countBits(n);
    showV(ans);
    int tmp = n&(n-1);
    cout << tmp << endl;
    //cout << ans << endl;
}
