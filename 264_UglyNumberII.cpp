#include "leetcode.h"
class Solution {
public:
    // 264. Ugly Number II
    int nthUglyNumber(int n) {
        set<long long> nums;
        nums.insert(1);
        for(int i = 0 ; i < n - 1; i++){
            auto tmp = nums.begin();
            nums.insert(*tmp * 2);
            nums.insert(*tmp * 3);
            nums.insert(*tmp * 5);
            nums.erase(tmp);
        }
        return *nums.begin();
    }
};

int main() {
    Solution s1;
    auto ans = s1.nthUglyNumber(1690);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
