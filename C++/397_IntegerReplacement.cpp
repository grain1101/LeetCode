#include "leetcode.h"

// 397. Integer Replacement
class Solution {
public:
    int integerReplacement(int n) {
        if (n <= 1) return 0;
        if (n % 2 == 0) return dfs(n);
        return min(dfs(n - 1LL), dfs(n + 1LL)) + 1;
    }
private:
    int dfs(long long n){
        if (n <= 1) return 0;
        if (n%2!=0) return min(dfs(n - 1), dfs(n + 1)) + 1;
        else return dfs(n / 2) + 1;
    }
};


int main() {
    Solution s1;
    auto ans = s1.integerReplacement(16);
    cout << ans << endl;
}
