#include "leetcode.h"
class Solution {
public:
    // 573. Squirrel Simulation
    int distance(int x1, int y1, int x2, int y2){
        return abs(x1-x2) + abs(y1-y2);
    }
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int allNutsToTree = 0;
        for(int i = 0; i < nuts.size(); i++){
            allNutsToTree += 2 * distance(tree[0], tree[1], nuts[i][0], nuts[i][1]);
        }
        int ret = INT_MAX;
        for(int i = 0; i < nuts.size(); i++){
            int tmp = distance(squirrel[0], squirrel[1], nuts[i][0], nuts[i][1]) - distance(tree[0], tree[1], nuts[i][0], nuts[i][1]);
            ret = min(ret, allNutsToTree + tmp);
        }
        return ret;
    }
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
