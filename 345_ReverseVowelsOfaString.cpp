#include "leetcode.h"

// 345. Reverse Vowels of a String
class Solution {
public:
    string reverseVowels(string s) {
        if (s.size() < 2) return s;
        int i = 0, j = s.size() - 1;
        while(i < j){
            while(!checkVowels(s[i])) i++;
            while(!checkVowels(s[j])) j--;
            if (i >= j) break;
            swap(s[i++], s[j--]);
        }
        return s;
    }
    // find_first_of(str, pos)
    // find_last_of(str, pos)
    string reverseVowels_buildIn(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
private:
    bool checkVowels(char c){
        if (c >= 'A' && c <='Z') c = c - ('Z' - 'z');
        return (c == 'a') || (c == 'e')|| (c == 'i') || (c == 'o') || (c == 'u');
    }
};

int main() {
    Solution s1;
    string s = "leetcode";
    auto ans = s1.reverseVowels(s);
    cout << ans << endl;
}
