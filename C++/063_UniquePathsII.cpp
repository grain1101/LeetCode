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
    // 63. Unique Paths II
    // DP[i][j]
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 0; i < m; i++){
            for(int j = 0;j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    if(i == 0){
                        int p = j;
                        while(p < n) dp[i][p++] = 0;
                    }
                    if(j == 0){
                        int p = i;
                        while(p < m) dp[p++][j] = 0;
                    }
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(dp[i][j] == 0) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    auto result = s1.uniquePaths(1,1);
    cout << result << endl;
    return 0;
}
