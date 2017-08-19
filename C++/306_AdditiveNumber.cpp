#include "leetcode.h"

class Solution {
public:
    // 306. Additive Number
    bool dfs(const string& num, int idx, long long a, long long b){
        if (idx == num.size()) return true;
        string c = to_string(a + b);
        for(int i = 0; i < c.size(); i++){
            if (num[idx + i] != c[i]) return false;
        }
        return dfs(num, idx + c.size(), b, a + b);
    }
    bool isAdditiveNumber(string num) {
        for(int i = 0; i < num.size() && i < max_len; i++){
            if (i > 0 && num[0] == '0') break;
            for(int j = i + 1; j < num.size() && j - i <= max_len; j++){
                if (j - i > 1 && num[i + 1] == '0') break;
                if (j + 1 == num.size()) continue;
                long long a = stoll(num.substr(0,i + 1));
                long long b = stoll(num.substr(i + 1, j - i));
                if (dfs(num, j + 1, a, b)) return true;
            }
        }
        return false;
    }
private:
    const int max_len = 10; // 32-bit Integer
};

int main() {
    Solution s1;
    string s = "112358";
    auto ans = s1.isAdditiveNumber(s);
    cout << ans << endl;
//    showV(ans);
    //show(ans);
    //showV(ans);
}
