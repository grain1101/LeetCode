#include "leetcode.h"

// 447. Number of Boomerangs
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ret = 0;
        for(auto& p : points){
            unordered_map<double, int> cnt(points.size());
            for(auto& q : points){
                ret += 2 * cnt[hypot(p.first - q.first, p.second - q.second)]++;
            }
        }
        return ret;
    }
};

int main() {
    Solution s1;
    auto ans = s1.convertToBase7(-7);
    //showV(ans);
    cout << ans << endl;
}
