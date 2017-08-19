#include "leetcode.h"

// 493. Reverse Pairs
typedef pair<int, int> PII;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        vector<PII> f(nums.size());
        for(int i = 0; i < nums.size(); i++){
            f[i].first = nums[i];
            f[i].second = -(i + 1);
        }
        sort(f.begin(), f.end());
        tree.assign(nums.size() + 1, 0);
        int ret = 0;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            for(; j <  nums.size() && f[j].first * 2LL < f[i].first; j++){
                add(-f[j].second, 1);
            }
            ret += getSum(nums.size()) - getSum(-f[i].second);
        }
        return ret;
    }
private:
    vector<int> tree;
    // get sum of [1,i];
    int getSum(int i){
        int ret = 0;
        //cout << i << " ";
        while(i > 0){
            ret += tree[i];
            i -= lowBit(i);
        }
        //cout << ret << endl;
        return ret;
    }
    void add(int i, int val){
        //cout << "add: " << i << " " << val << endl;
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
    vector<int> nums = {-5,-5};
    auto ans = s1.reversePairs(nums);
    //showV(ans);
    cout << ans << endl;
}
