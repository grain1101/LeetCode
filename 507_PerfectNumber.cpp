#include "leetcode.h"

// 507. Perfect Number
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 0) return false;
        int ret = 0;
        for(int i = 1; i < sqrt(num); i++){
            if (num % i == 0){
                ret += i;
                if (i != 1) ret += num / i;
            }
        }
        return ret == num;
    }
};

int main() {
    Solution s1;
    int num = 28;
    auto ans = s1.checkPerfectNumber(num);
    cout << ans << endl;
}
