#include "leetcode.h"

// 461. Hamming Distance
class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0, n = x ^ y;
        while(n){
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
};


int main() {
    Solution s1;
    auto ans = s1.hammingDistance(1,4);
    //showV(ans);
    cout << ans << endl;
}
