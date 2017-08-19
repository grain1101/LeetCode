#include "leetcode.h"

// 387. First Unique Character in a String
class Solution {
public:
    int firstUniqChar(string s) {
        for(int i = 0; i < s.size(); i++){
            size_t first = s.find_first_of(s[i]);
            size_t last = s.find_last_of(s[i]);
            if (first == last) return i;
        }
        return -1;
    }
};

int main() {
    Solution s1;
    string s = "ccb";
    auto ans = s1.firstUniqChar(s);
    cout << ans << endl;

    string ss = "aaa";
//    cout << ss.find_first_of("a", 0) << endl;
//    cout << ss.find_last_of("a") << endl;
}
