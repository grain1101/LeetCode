#include "leetcode.h"

// 463. Island Perimeter
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0, repeat = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if (grid[i][j]){
                    cnt++;
                    // up and left;
                    if (i > 0 && grid[i - 1][j] == 1) repeat++;
                    if (j > 0 && grid[i][j - 1] == 1) repeat++;
                }
            }
        }
        return 4 * cnt - 2 * repeat;
    }
};


int main() {
    Solution s1;
    auto ans = s1.hammingDistance(1,4);
    //showV(ans);
    cout << ans << endl;
}
