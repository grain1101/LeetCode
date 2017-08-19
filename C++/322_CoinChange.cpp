#include "leetcode.h"

class Solution {
public:
    // 322. Coin Change
    // DP
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if (coins[j] <= i)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
            //showV(dp);
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    Solution s1;
    vector<int> coins = {1,2,3};
    int amount = 6;
    auto ans = s1.coinChange(coins, amount);
    cout << ans << endl;
}
