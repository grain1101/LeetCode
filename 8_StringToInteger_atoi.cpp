#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 8. String to Integer (atoi)
    // Input: 123; -123
    // Output:123
    int myAtoi(string s) {
        // 000123;+123;-123;INT_MAX;   111
        // error cases: 23#345; 1 222  3;  -0012a42; +-2;
        int ans = 0;
        int flag = 1;
        int i=0;
        while(s[i]==' '){i++;}
        if(s[i] == '-' || s[i] == '+'){
            flag = s[i++]=='+'?1:-1;
        }
        int overflow = 0;
        while(isdigit(s[i])){
            int digits = s[i] - '0';
            if(ans > (INT_MAX-digits) / 10.0){
                overflow = 1;
                break;
            }
            ans = ans*10 + digits;
            i++;
        }
        if(overflow){
            return flag==1?INT_MAX:INT_MIN;
        }
        return flag * ans;
    }
};

int main()
{
    // 1. Input test cases
    int num = -2147483648;
    string s = "  d-1";
    // 2. Run
    Solution s1;
    auto result = s1.myAtoi(s);
    // 3. Compare output
    cout << result << endl;
    return 0;
}
