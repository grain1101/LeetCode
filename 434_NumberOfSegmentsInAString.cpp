#include "leetcode.h"

// 434. Number of Segments in a String
class Solution {
public:
    int countSegments(string s) {
        int ret = 0;
        for(int i = 0; i < s.size(); i++){
            if (s[i] == ' ') continue;
            ret++;
            int j = i;
            while(j < s.size() && s[j] != ' ') j++;
            i = j - 1;
        }
        return ret;
    }
};



int main() {
    Solution s1;
    string s = "Hello 2";
    auto ans = s1.countSegments(s);
    //showV(ans);
    cout << ans << endl;
}
