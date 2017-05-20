#include "leetcode.h"

// 412. Fizz Buzz
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret(n);
        for(int i = 1; i <= n; i++){
            if (i % 3 == 0 && i % 5 == 0) ret[i - 1] = "FizzBuzz";
            else if (i % 3 == 0)   ret[i - 1] = "Fizz";
            else if (i % 5 == 0)   ret[i - 1] = "Buzz";
            else ret[i - 1] = to_string(i);
        }
        return ret;
    }
};

int main() {
    Solution s1;
    int num = -3;
    auto ans = s1.toHex(num);
    cout << ans << endl;
}
