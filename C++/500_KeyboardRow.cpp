#include "leetcode.h"

// 500. Keyboard Row
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> keyboard = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        vector<string> ret;
        for(string s : words){
            int i = 0, j = 0;
            for(; j < 3; j++){
                if (keyboard[j].find(s[0]) != string::npos) break;
            }
            for(; i < s.size(); i++){
                if (keyboard[j].find(s[i]) == string::npos) break;
            }
            if (i == s.size()) ret.push_back(s);
        }
        return ret;
    }
};


int main() {
    Solution s1;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    auto ans = s1.findWords(words);
    showV(ans);
    //cout << ans << endl;
}
