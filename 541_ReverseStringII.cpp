#include "leetcode.h"

// 541. Reverse String II
class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0, j = 0;
        int cnt = 0;
        while(i < s.size()){
            cout << i << " " << j << endl;
            while(j < s.size() && j - i < k ){
                j++;
            }
            j--;
            while(i < j){
                swap(s[i++], s[j--]);
            }
            cnt++;
            i = cnt * 2 * k;
            j = i + 1;
        }
        return s;
    }
};

int main() {
    Solution s1;
    string s = "abcdefg";
    int k = 2;
    auto ans = s1.reverseStr(s, k);
    cout << ans << endl;
}
