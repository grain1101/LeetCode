#include "leetcode.h"

class Solution {
public:
    // 290. Word Pattern
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> mapping;
        unordered_map<char, char> patterns;
        char s = 'a';
        int j = 0;
        string ret = "";
        for(int i = 1; i <= str.size(); i++){
            if (i == str.size() || str[i] == ' '){
                string tmp = str.substr(j, i - j);
                j = i + 1;
                //cout << tmp << endl;
                if (mapping.find(tmp) == mapping.end()){
                    mapping[tmp] = s;
                    s++;
                }
                ret += mapping[tmp];
            }
        }
        s = 'a';
        string pat = "";
        for(auto c : pattern){
            if (patterns.find(c) == patterns.end()){
                patterns[c] = s;
                s++;
            }
            pat += patterns[c];
        }
        //cout << pat << endl;
        return pat == ret;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {2,3,1,4,3};
    string s = "e";
    string ss = "eukera";
    auto ans = s1.wordPattern(s,ss);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
