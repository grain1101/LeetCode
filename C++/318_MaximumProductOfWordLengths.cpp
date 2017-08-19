#include "leetcode.h"

class Solution {
public:
    // 318. Maximum Product of Word Lengths
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size());
        int ret = 0;
        for(int i = 0; i < words.size(); i++){
            for(char c : words[i]){
                mask[i] |= 1 << (c - 'a');
            }
            for(int j = 0; j < i; j++){
                if (!(mask[i] & mask[j]))
                    ret = max(ret, int(words[i].size() * words[j].size()));
            }
        }
        return ret;
    }
};

int main() {
    Solution s1;
    auto ans = s1.maxProduct(words);
    cout << ans << endl;
//    showV(ans);
    //show(ans);
    //showV(ans);
}
