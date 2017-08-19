#include "leetcode.h"

// 611. Valid Triangle Number
// binary search
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, l = 0, r = n, mid;
        for(i = 0; i < n; i++){
            for(j = i + 1; j < n; j++){
                int sum = nums[i] + nums[j];
                l = j; r = n;
                while(l + 1 < r){
                    mid = (l + r) / 2;
                    if (nums[mid] >= sum) r = mid;
                    else l = mid;
                }
                ret += l - j;
            }
        }
        return ret;
    }
};


int main() {
    Solution s1;
    //vector<int> nums = {48,66,61,46,94,75};
    vector<int> nums = {2,2,2};
    auto ans = s1.triangleNumber(nums);
    cout << ans << endl;
}
