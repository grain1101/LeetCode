#include "leetcode.h"

// 438. Find All Anagrams in a String
// sliding window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        vector<int> cnt(26);
        changeInput(s);
        changeInput(p);
        for(int i = 0; i < p.size(); i++){
            cnt[p[i]]++;
        }
        int head = 0;
        for(int i = 0; i < s.size(); i++) {
            cnt[s[i]]--;
            while(cnt[s[i]] < 0) cnt[s[head++]]++;
            if (i - head + 1 == p.size()) ret.push_back(head);
        }
        return ret;
    }
private:
    void changeInput(string& s){
        for(auto& ss : s){
            ss = ss - 'a';
        }
    }
};

int main() {
    Solution s1;
    int num = 28;
    auto ans = s1.checkPerfectNumber(num);
    cout << ans << endl;
}
