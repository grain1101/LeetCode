#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

class Solution {
public:
    // 3. Longest Substring Without Repeating Characters
    // Input: abcabcbb; bbbbb; pwwkew
    // Output: 3(abc); 1(b); 3(wke)
    int lengthOfLongestSubstring(string s) {
        // Slide Window
        int characters[128] = {0};
        int start = 0;
        int result = 0;
        for(int i=0;i<s.size();i++){
            // first add s[i] to character[s[i]]
            // then determine whether this char Repeating
            characters[s[i]]++;
            while(characters[s[i]]!=1) {
                characters[s[start]]--;
                start++;
            }
            result = max(result, i-start+1);
        }
        return result;
    }
};

int main()
{
    // 1. Input test cases
    string s = "abcabcbb";

    // 2. Run
    Solution s1;
    auto result = s1.lengthOfLongestSubstring(s);

    // 3. Compare output
    cout << result << endl;
    return 0;
}
