#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 5. Longest Palindromic Substring
    // Input: babad; cbbd
    // Output: bab; bb
    string longestPalindrome(string s) {
        int len = s.size();
        string result;
        // even
        for(int i=0;i<len;i++){
            int l = i-1;
            int r = i;
            while(l>=0 && r<len && s[r] == s[l]){
                r++;l--;
            }
            if(result.size() < r-l-1){
                result = s.substr(l+1, r-l-1);
            }
        }
        // odd
        for(int i=0;i<len;i++){
            int l = i-1;
            int r = i+1;
            while(l>=0 && r<len && s[r]==s[l]){
                r++;l--;
            }
            if(result.size() <  r-l-1){
                result = s.substr(l+1, r-l-1);
            }
        }
        return result;
    }
};

int main()
{
    // 1. Input test cases
    string s = "cbbd";

    // 2. Run
    Solution s1;
    auto result = s1.longestPalindrome(s);

    // 3. Compare output
    cout << result << endl;
    return 0;
}
