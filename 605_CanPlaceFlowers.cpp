#include "leetcode.h"

// 605. Can Place Flowers
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ret = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            if (flowerbed[i] == 0){
                if ((i == 0 && flowerbed[i + 1] == 0) || (i == flowerbed.size() - 1 && flowerbed[i - 1] == 0)) flowerbed[i] = 1, ret++;
                else if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) flowerbed[i] = 1, ret++;
            }
        }
        return ret >= n;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,3,2,2,2};
    auto ans = s1.findUnsortedSubarray(nums);
    //showV(ans);
    cout << ans << endl;
}
