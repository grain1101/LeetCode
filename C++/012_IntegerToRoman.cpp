#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 12. Integer to Roman
    // input:[1, 3999]
    // Roman:
    string intToRoman(int num) {
        char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "IC"};
        char *huns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ans;
        while(num>=1000){
            ans += 'M';
            num -= 1000;
        }
        ans += huns[num/100];
        num %= 100;
        ans += tens[num/10];
        num %= 10;
        ans += ones[num];
        return ans;
    }
};

int main()
{
    // 1. Input test cases
    int num = 999;
//    vector<int> nums = {3,2,1,3};
//    string ss1 = "abbc";
//    string ss2 = "ab*bbc";

    // 2. Run
    Solution s1;
    auto result = s1.intToRoman(num);

    // 3. Compare output

    cout << result << endl;
    return 0;
}
