#include "leetcode.h"

// 389. Find the Difference
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ret = 0;
        for(auto c : s) ret = ret ^ c;
        for(auto c : t) ret = ret ^ c;
        return ret;
    }
};
