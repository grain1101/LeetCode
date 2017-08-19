#include "leetcode.h"

// 420. Strong Password Checker
class Solution {
    const int minLen = 6;
    const int maxLen = 20;
    int classify(char c) {
        if (isdigit(c)) return (1<<0);
        if (islower(c)) return (1<<1);
        return (1<<2);
    }
public:
    int strongPasswordChecker(string s) {
         int mask = 0;
         int sz = 0;
         int wild = 0;
         if (s.size() < minLen) sz = s.size() - minLen;
         if (s.size() > maxLen) sz = s.size() - maxLen;
         int ret = abs(sz);
         if (sz < 0) wild = -sz;
         vector<int> ks;
         for(int i = 0; i < s.size(); i++) {
             mask |= classify(s[i]);
             int j = i + 1;
             while(j < s.size() && s[j] == s[i]) j++;
             int k = j - i;
             i = j - 1;
             if (k < 3) continue;
             ks.push_back(k);
         }
         int remove = 0;
         if (sz > 0) {
             for(int i = 0; sz > 0 && i < ks.size(); i++) {
                 if (ks[i] % 3 == 0) {
                     ks[i]--;
                     sz--;
                 }
             }
             for(int i = 0; sz > 1 && i < ks.size(); i++) {
                 if (ks[i] % 3 == 1) {
                     ks[i] -= 2;
                     sz -= 2;
                 }
             }
             remove = sz / 3;
         } else if (sz < 0) {
             sz = -sz;
             for(auto &k : ks) {
                 int needadd = (k - 1) / 2;
                 int added = min(needadd, sz);
                 k -= 2 * added;
                 sz -= added;
             }
         }
        int change = 0;
        for(auto k : ks) change += k / 3;
        change = max(0, change - remove);
        wild += change;
        ret += change;
        return ret + max(0, 3 - __builtin_popcount(mask) - wild);
    }
};


int main() {
    Solution s1;
    auto ans = s1.hammingDistance(1,4);
    //showV(ans);
    cout << ans << endl;
}
