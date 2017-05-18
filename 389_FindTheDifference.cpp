#include "leetcode.h"

// 389. Find the Difference
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i = 0; i < t.size(); i++){
            if (t[i] != s[i]) return t[i];
            if (i == s.size() - 1) return t[i + 1];
        }
    }
};

int main() {
    Solution s1;
    string s = "ae";
    string t = "aea";
    auto ans = s1.findTheDifference(s, t);
    cout << ans << endl;

    string ss = "aaa";
//    cout << ss.find_first_of("a", 0) << endl;
//    cout << ss.find_last_of("a") << endl;
}
