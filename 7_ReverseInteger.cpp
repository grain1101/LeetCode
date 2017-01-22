#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 7. Reverse Integer
    // Input: 123; -123
    // Output: 321; -321
    int reverse(int x) {
        /// if x or -x or reverse(x) is overflow, return 0
        int flag = 1;
        if(x<0) flag = -1;
        long long ans = 0;
        long long tmp = abs(x*1LL);
        while(tmp){
            ans = ans*10 + tmp%10;
            tmp = tmp/10;
        }
        if(ans>INT_MAX || flag * ans < INT_MIN) return 0;
        return flag * ans;
    }
};

int main()
{
    // 1. Input test cases
    int num = -2147483648;

    // 2. Run
    Solution s1;
    auto result = s1.reverse(num);
    // 3. Compare output
    cout << result << endl;
    return 0;
}
