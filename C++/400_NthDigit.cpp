#include "leetcode.h"

// 400. Nth Digit
class Solution {
public:
    int findNthDigit(int n) {
        int digits = 1; // 1 ; 2; 3;
        long long counts = 9; //[1,9]->9; [10,99]->90; [100, 999]->900;
        int start = 1;
        while(n > digits * counts){
            n -= digits * counts;
            digits++;
            counts *= 10;
            start *= 10;
        }
        cout << "digits: " << digits << endl;
        cout << "counts: " << counts << endl;
        start += (n - 1) / digits;
        string ret = to_string(start);
        return ret[(n - 1) % digits] - '0';
    }
};

int main() {
    Solution s1;
    string s = "ae";
    string t = "aea";
    auto ans = s1.findNthDigit(1000000000);
    cout << ans << endl;

    string ss = "aaa";
//    cout << ss.find_first_of("a", 0) << endl;
//    cout << ss.find_last_of("a") << endl;
}
