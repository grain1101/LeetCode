#include "leetcode.h"

class NumArray {
public:
    // 307. Range Sum Query - Mutable
    NumArray(vector<int> nums) {
        this->nums = nums;
        tree.assign(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            add(i + 1, nums[i]);
        }
    }

    void update(int i, int val) {
        add(i + 1, val - nums[i]);
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
private:
    vector<int> tree;
    vector<int> nums;
    int getSum(int i){
        int ret = 0;
        while(i > 0){
            ret += tree[i];
            i -= lowBit(i);
        }
        return ret;
    }
    void add(int i, int val){
        while(i < tree.size()){
            tree[i] += val;
            i += lowBit(i);
        }
    }
    int lowBit(int n){
        return  n ^ (n & (n - 1));
    }
};

int main() {
    Solution s1;
    string s = "112358";
    auto ans = s1.isAdditiveNumber(s);
    cout << ans << endl;
//    showV(ans);
    //show(ans);
    //showV(ans);
}
