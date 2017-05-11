#include "leetcode.h"

class NumArray {
public:
    // 303. Range Sum Query - Immutable
    NumArray(vector<int> nums) {
        d.assign(nums.size(), 0);
        sum(nums);
    }
    int sumRange(int i, int j) {
        return i == 0 ? d[j] : d[j] - d[i - 1];
    }
private:
    vector<int> d;
    void sum(vector<int>& nums){
        for(int i = 0; i < nums.size(); i++){
            if (i == 0) d[0] = nums[0];
            else d[i] = d[i - 1] + nums[i];
        }
    }
};


int main() {

    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(nums);
    auto ans = obj->sumRange(0,5);
    cout << ans << endl;
//    showV(ans);
    //show(ans);
    //showV(ans);
}
