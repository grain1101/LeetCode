#include "leetcode.h"

// 414. Third Maximum Number
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = INT_MIN - 1LL, second = INT_MIN - 1LL, third = INT_MIN - 1LL;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == first || nums[i] == second || nums[i] == third) continue;
            if (nums[i] > first){
                third = second;
                second = first;
                first = nums[i];
            }
            else if (nums[i] > second){
                third = second;
                second = nums[i];
            } else if (nums[i] > third){
                third = nums[i];
            }
        }
        if (third != INT_MIN - 1LL) return third;
        return first;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {2,2,3,1};
    auto ans = s1.thirdMax(nums);
    cout << ans << endl;
}
