#include "leetcode.h"
class Solution {
public:
    // 576. Out of Boundary Paths
    int outBoundary(int p, int q){
        int ret = 0;
        if (p - 1 < 0) ret++;
        if (p + 1 >= n) ret++;
        if (q - 1 < 0) ret++;
        if (q + 1 >= m) ret++;
        return ret;
    }
    bool inBoundary(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    int findPaths(int _m, int _n, int N, int p, int q) {
        m = _m; n = _n;
        int mod = 1000000000+7;
        vector<vector<int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<vector<int>>> dp (N, vector<vector<int>>(m, vector<int>(n, 0)));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < n; k++){
                    if (i == 0){
                        dp[i][j][k] = outBoundary(j,k);
                    }
                    else {
                        for(int t = 0; t < 4; t++){
                            int x = j + direction[t][0];
                            int y = k + direction[t][1];
                            if (inBoundary(x,y)) dp[i][j][k] += dp[i - 1][x][y];
                            dp[i][j][k] %= mod;
                        }

                    }
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < N; i++){
            ret += dp[i][p][q];
            ret %= mod;
        }
        return ret;
    }
private:
    int m;
    int n;
};

int main() {
    Solution s1;
    vector<int> nums = {0,1,2,4};
    auto ans = s1.minDistance();
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
