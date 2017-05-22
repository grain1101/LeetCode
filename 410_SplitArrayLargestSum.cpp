#include "leetcode.h"

// 410. Split Array Largest Sum
// binary search
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long l = 0, r = 0;
        _nums = nums;
        _m = m;
        for(auto n : nums){
            r += n;
            l = max(l, (long long)n);
        }
        while(l < r) {
            long long mid = (l + r) / 2;
            if (canSplit(mid)) r = mid;
            else l = mid+1;
        }
        return l;
    }
    bool canSplit(long long x){
        int n = 1;
        long long sum = 0;
        for(int i = 0; i < _nums.size(); i++){
            if (sum + _nums[i] > x) {
                n++;
                sum = 0;
            }
            sum += _nums[i];
        }
        return n <=  _m;
    }
private:
    vector<int> _nums;
    int _m;
};

int main() {
    Solution s1;
    vector<int> nums = {1,2147483647};
    auto ans = s1.splitArray(nums, 2);
    cout << ans << endl;
}
