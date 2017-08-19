#include "leetcode.h"

// 386. Lexicographical Numbers
// [1,10,100,101,102,103,104,105,106,107,108,109,[11,110],111,112...]
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n, 0);
        int cur = 1;
        for(int i = 0; i < n; i++){
            ret[i] = cur;
            if (cur * 10 <= n){
                cur *= 10;
            }
            else {
                if (cur >= n){
                    cur /= 10;
                }
                cur += 1;
                while(cur % 10 == 0){
                    cur /= 10;
                }
            }
        }
        return ret;
    }
};


int main() {
    Solution s1;
    int n = 234;
    auto ans = s1.lexicalOrder(n);
    cout << ans << endl;
}
