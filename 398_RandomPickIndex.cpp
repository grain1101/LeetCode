#include "leetcode.h"

// 398. Random Pick Index
class Solution {
public:
    Solution(vector<int> _nums) {
        srand (time(NULL));
        nums = _nums;
    }

    int pick(int target) {
        int ret = -1, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != target) continue;
            cnt++;
            if (cnt == 1) {
                ret = i;
            } else{
                int j = rand()%cnt;
                if (j == 0) ret = i;
            }

        }
        return ret;
    }
private:
    vector<int> nums;
};





int main() {
    vector<int> nums = {1};
    Solution *s1 = new Solution(nums);
    auto ans = s1->pick(1);
    cout << ans << endl;
}
