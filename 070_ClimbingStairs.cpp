#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
}

class Solution {
  public:
    // 70. Climbing Stairs
    // DP
    int climbStairs(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n + 1, 1);
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    auto result = s1.climbStairs(2);
    cout << result << endl;
    return 0;
}
