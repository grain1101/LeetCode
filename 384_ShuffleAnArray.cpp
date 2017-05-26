#include "leetcode.h"

// 384. Shuffle an Array
class Solution {
public:
    vector<int> nums;
    Solution(vector<int> nums) {
        srand(time(NULL));
        this->nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret(nums);
        for(int i = 0; i < nums.size(); i++){
            int pos = rand()%(nums.size());
            swap(ret[i], ret[pos]);
        }
        return ret;
    }
};


int main() {
    vector<int> nums = {1,2,3,4};
    Solution *s1 = new Solution(nums);
    auto ans = s1->shuffle();
    showV(ans);
    //cout << ans << endl;
}
