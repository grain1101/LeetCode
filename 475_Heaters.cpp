#include "leetcode.h"

// 475. Heaters
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (heaters.size() == 0) return 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ret = 0;
        int idx = 0;
        for(int i = 0; i < houses.size(); i++){
            while(idx + 1 < heaters.size() && (abs(heaters[idx + 1] - houses[i]) <= abs(heaters[idx] - houses[i]))){
                idx++;
            }
            ret = max(ret, abs(heaters[idx] - houses[i]));
        }
        return ret;
    }
};

int main() {
    Solution s1;
    vector<int> houses = {1,2,3,4};
    vector<int> heaters = {1, 4};
    auto ans = s1.findRadius(houses, heaters);
    cout << ans << endl;
}
