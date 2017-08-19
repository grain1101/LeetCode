#include "leetcode.h"

// 383. Ransom Note
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mapping;
        for(auto c : magazine){
            mapping[c]++;
        }
        int ret = 0;
        for(char c : ransomNote){
            if (mapping.find(c) == mapping.end() || mapping[c] == 0) return false;
            mapping[c]--;
            ret++;
        }
        return ret==ransomNote.size();
    }
};

int main() {
    Solution s1;
    auto ans = s1.guessNumber(7);
    cout << ans << endl;
}
