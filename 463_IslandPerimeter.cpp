#include "leetcode.h"

// 463. Island Perimeter
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        this->grid = grid;
        ret = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if (grid[i][j]) dfs(i, j);
            }
        }
        return ret;
    }
private:
    vector<vector<int>> grid;
    int ret;
    vector<vector<int>> d = {{-1,0},{0,1},{1,0},{0,-1}};
    bool checkBoundary(int p, int q){
        return p >= 0 && p < grid.size() && q >=0 && q < grid[0].size();
    }
    void dfs(int p, int q){
        if (!checkBoundary(p, q) || grid[p][q] == 0) {
            ret++;
            return;
        }
        if (grid[p][q] == -1) return;
        grid[p][q] = -1;
        for(int i = 0; i < 4; i++){
            dfs(p + d[i][0], q + d[i][1]);
        }
    }
};


int main() {
    Solution s1;
    auto ans = s1.hammingDistance(1,4);
    //showV(ans);
    cout << ans << endl;
}
