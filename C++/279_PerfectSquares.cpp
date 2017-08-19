#include "leetcode.h"
bool isBadVersion(int version){
    return version >= 1 ;
}

class Solution {
public:
    // 279. Perfect Squares
    // n = 4^k(8 * m + b)
    bool isSquare(int n){
        int sqrt_n = sqrt(n);
        return sqrt_n * sqrt_n == n;
    }
    int numSquares(int n) {
        if (isSquare(n)) return 1;
        while(n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) return 4;
        int sqrt_n = sqrt(n);
        for(int i = 1; i <= sqrt_n; i++){
            if (isSquare(n - i * i)) return 2;
        }
        return 3;
    }
};


int main() {
    Solution s1;
    vector<int> nums = {12};
    auto ans = s1.firstBadVersion(2);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
