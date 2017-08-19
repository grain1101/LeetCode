#include "leetcode.h"
class Solution {
public:
    // 233. Number of Digit One
//    int dfs(int idx, bool end_flag) {
//        if (idx == nstr.size()) return 0;
//        int &tmp = dp[idx][end_flag];
//        if (tmp != -1) return tmp;
//        tmp = 0;
//        int end_digit = end_flag ? nstr[idx] - '0' : 9;
//        for(int i = 0; i <= end_digit; i++) {
//            tmp += dfs(idx + 1, end_flag && i == end_digit);
//            if (i == 1) {
//                int pre = 0;
//                if (idx + 1 == nstr.size()) pre = 0;
//                else {
//                    string tmp;
//                    if (end_flag && i == end_digit) tmp = nstr.substr(idx+1);
//                    else tmp = string(nstr.size() - idx - 1, '9');
//                    pre = stoi(tmp);
//                }
//                tmp += pre + 1;
//            }
//        }
//        return tmp;
//    }
//
//    int countDigitOne(int _n) {
//        n = _n;
//        nstr = to_string(n);
//        dp.assign(32, vector<int>(2, -1));
//        return dfs(0, true);
//    }
    int countDigitOne_recursive(int n){
        if (n < 1) return 0;
        if (n >=1 && n < 10) return 1;
        int y = 1, x = n;
        while (!(x < 10)){
            x /= 10;
            y *= 10;
        }
        cout << "n:" << n << " x:" << x << " y:" << y << endl;
        if (x == 1){
            cout << n << '-' << y << " + 1 + cout(" << y - 1 << ") + cout(" << n%y << ")" << endl;
            return n - y + 1 + countDigitOne_recursive(y - 1) + countDigitOne_recursive(n % y);
        }
        else {
            cout << y << '+' << x << " * cout(" << y - 1 << ") + cout(" << n%y << ")" << endl;
            return y + x * countDigitOne_recursive(y - 1) + countDigitOne_recursive(n % y);
        }
    }
private:
    vector<vector<int>> dp;
    int n;
    string nstr;
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,4};
    auto ans = s1.countDigitOne_recursive(118);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
