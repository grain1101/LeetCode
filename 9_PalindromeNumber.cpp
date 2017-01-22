#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 9. Palindrome Number
    // Input: 1221; -123
    // Output:true;false

    ///  Memory Limit Exceeded: 2147483647
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        int bits = 1;
        /// pay attention to integer overflow
        while(x/bits >= 10){
            bits *=10;
        }
        while(x){
            if(x/bits != x%10) return false;
            x = x%bits/10;
            bits = bits/100;
        }
        return true;
    }
};

int main()
{
    // 1. Input test cases
    int num = 1001;
    string s = "  d-1";
    // 2. Run
    Solution s1;
    auto result = s1.isPalindrome(num);
    // 3. Compare output
    cout << result << endl;
    return 0;
}
