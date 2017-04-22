#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <set>
#include <string>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t << " ";
        }
        cout << endl;
    }
}
void showV(auto& result){
    for(auto r : result)
        cout << r << " ";
    cout << endl;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 struct TreeNode {
    int val;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Solution {
public:
    // 188. Best Time to Buy and Sell Stock IV
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.size() == 0) return 0;
        if (k >= (prices.size() + 1)/ 2){
            int ans = 0;
            for(int i = 1; i < prices.size(); i++){
                if (prices[i] > prices[i - 1]) ans += prices[i] - prices[i - 1];
            }
            return ans;
        }
        vector<int> dp(k * 2, INT_MIN);
        for(int i = 0; i < prices.size(); i++){
            for(int j = 0; j < 2 * k; j++){
                if (j == 0){
                    dp[j] = max(dp[j], -prices[i]);
                } else if (j % 2){
                    dp[j] = max(dp[j], dp[j - 1] + prices[i]);
                } else {
                    dp[j] = max(dp[j], dp[j - 1] - prices[i]);
                }
            }
        }
        return dp[2 * k - 1];
    }
};

int main() {
    Solution s1;
    vector<int> nums = {};
    auto ans = s1.maxProfit(3, nums);
    return ans;
}
