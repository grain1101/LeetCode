#include "leetcode.h"

// 581. Shortest Unsorted Continuous Subarray
class Solution {
public:
    int findUnsortedSubarray_sort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int i, ret = nums.size();
        for(i = 0; i < nums.size(); i++){
            if (nums[i] != tmp[i]) break;
        }
        if (i == nums.size()) return 0;
        //cout << i << endl;
        ret -= i;
        for(i = nums.size()- 1; i >=0;i--){
            if (nums[i] != tmp[i]) break;
        }
        //cout << i << endl;
        ret -= (nums.size() - i - 1);
        return ret;
    }
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n, nums[0]);
        vector<int> rightMin(n, nums[n - 1]);
        for(int i = 1; i < n; i++){
            leftMax[i] = (nums[i] >= leftMax[i - 1]) ? nums[i] : leftMax[i - 1];
        }
        for(int i = n - 2; i >= 0; i--){
            rightMin[i] = (nums[i] <= rightMin[i + 1]) ? nums[i] : rightMin[i + 1];
        }
        int i = 0, j = n - 1;
        for(; i < n; i++){
            if (leftMax[i] > rightMin[i]) break;
        }
//        showV(leftMax);
//        showV(rightMin);
//        cout << "i:" << i << endl;
        if (i == n) return 0;
        for(; j >= 0; j--){
            if (leftMax[j] > rightMin[j]) break;
        }
//        cout << i << " " << j << endl;
        return j - i + 1;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,3,2,2,2};
    auto ans = s1.findUnsortedSubarray(nums);
    //showV(ans);
    cout << ans << endl;
}
