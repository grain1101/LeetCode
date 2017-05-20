#include "leetcode.h"

// 415. Add Strings
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) return addStrings(num2, num1);
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        for(; i>= 0 && (carry || j >=0);i--,j--){
            int var1 = num1[i] - '0';
            int var2 = (j >= 0)? num2[j] - '0' : 0;
            int sum = var1 + var2 + carry;
            num1[i] = sum % 10 + '0';
            carry = sum / 10;
        }
        return ((carry == 1) ?  "1" : "") + num1;
    }
};

int main() {
    Solution s1;
    string num1 = "9";
    string num2 = "9";
    auto ans = s1.addStrings(num1, num2);
    cout << ans << endl;
    //cout << 123+999<< endl;
}
