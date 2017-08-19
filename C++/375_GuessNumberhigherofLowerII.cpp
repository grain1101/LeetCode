#include "leetcode.h"

// 375. Guess Number Higher or Lower II
class Solution {
public:
    int getMoneyAmount(int n) {
        f.assign(n + 1, vector<int>(n + 1, -1));
        return dp(1, n);
    }
private:
    vector<vector<int>> f;
    int dp(int l, int r){
        if (l >= r) return 0;
        int& ret = f[l][r];
        if (ret != -1) return ret;
        for(int i = l; i <= r; i++){
            int tmp = i + max(dp(l, i - 1), dp(i + 1, r));
            if (ret == -1 || ret > tmp) ret = tmp;
        }
        return ret;
    }
};


int main() {
    Solution s1;
    auto ans = s1.getMoneyAmount()
    //showV(ans);
    cout << ans << endl;
}
