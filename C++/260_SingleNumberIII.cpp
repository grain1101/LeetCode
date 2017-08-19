#include "leetcode.h"
class Solution {
public:
    // 260. Single Number III
    vector<int> singleNumber(vector<int>& nums) {
        int aXorb = 0;
        for(auto n : nums){
            aXorb ^= n;
        }
        int lastBit = (aXorb & (aXorb - 1)) ^ aXorb;
        int A = 0, B = 0;
        for(auto n : nums){
            if (n & lastBit) A ^= n;
            else B ^= n;
        }
        return {A, B};
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
