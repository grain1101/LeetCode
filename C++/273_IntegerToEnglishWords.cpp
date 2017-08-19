#include "leetcode.h"
class Solution {
public:
    // 273. Integer to English Words
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        int i = 0;
        string ret = "";
        while(num > 0){
            if (num % 1000 != 0){
                ret = helper(num%1000) + hundreds[i] + " " + ret;
            }
            num /= 1000;
            i++;
        }
        size_t first = ret.find_first_not_of(" ");
        size_t last = ret.find_last_not_of(" ");
        return ret.substr(first, last-first + 1);
    }
private:
       vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                              "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
       vector<string> tens = {"","Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
       vector<string> hundreds = {"", "Thousand", "Million", "Billion"};
       string helper(int n){
            if (n == 0) return "";
            if (n < 20) return ones[n] + " ";
            if (n < 100) return tens[n/10] + " " + helper(n%10);
            if (n >= 100) return ones[n/100] + " Hundred " + helper(n%100);
       }
};

int main() {
    Solution s1;
    vector<int> nums = {0,1,2,4};
    auto ans = s1.numberToWords(123);
    cout << ans << "!" << endl;

    //showV(ans);
    //show(ans);
    //showV(ans);
}
