#include "leetcode.h"

// 565. Array Nesting
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<int> mark(nums.size(), 0);
        int ret = 0;
        for(int i = 0; i < nums.size(); i++){
            if (!mark[i]){
                findCircle(nums, mark, ret, i);
            }
        }
        return ret;
    }
private:
    void findCircle(const vector<int>& nums, vector<int>& mark, int& ret, int i){
        int tmp = 0;
        while(mark[i] == 0){
            mark[i] = 1;
            i = nums[i];
            tmp++;
        }
        ret = max(ret, tmp);
    }
};

int main() {
    Solution s1;
    vector<int> nums = {0,2,1};
    auto ans = s1.arrayNesting(nums);
    //showV(ans);
    cout << ans << endl;
}
