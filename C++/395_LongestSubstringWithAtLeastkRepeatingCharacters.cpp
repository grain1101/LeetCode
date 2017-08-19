#include "leetcode.h"

// 395. Longest Substring with At Least K Repeating Characters
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) return 0;
        if (k == 0) return s.size();
        return dfs(s, k, 0, s.size());
    }
    int dfs(const string& s, int k, int l, int r){
        vector<int> mapping(26, 0);
        for(int i = l; i < r; i++) mapping[s[i] - 'a']++;
        int ret = 0;
        for(int i = l; i < r; ){
            while(i < r && mapping[s[i] - 'a'] < k) i++;
            if (i == r) break;

            int j = i;
            while(j < r && mapping[s[j] - 'a'] >= k) j++;

            if (i == l && j == r) return r - l;
            ret = max(ret, dfs(s, k, i, j));

            i = j;
        }
        return ret;
    }
};


int main() {
    Solution s1;
    string s = "aaabb";
    int k = 3;
    auto ans = s1.longestSubstring(s, k);
    cout << ans << endl;
}
