#include "leetcode.h"
class Solution {
public:
    // 242. Valid Anagram
    bool isAnagram(string s, string t) {
        // hash table
        if (s.size() != t.size()) return false;
        if (s.size() == 0) return true;
        unordered_map<char, int> counts;
        for(int i = 0; i < s.size(); i++){
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for(auto c : counts){
            if (c.second) return false;
        }
        return true;
    }
    bool isAnagram_sort(string s, string t) {
        // sort
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,4};
    string s = "abc";
    string t = "bca";
    auto ans = s1.isAnagram(s, t);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
