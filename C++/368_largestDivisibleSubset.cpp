#include "leetcode.h"

// 368. Largest Divisible Subset
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<int> ret;
        vector<int> pre(n, -1);
        vector<int> cnt(n, 1);
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if (nums[j] % nums[i] == 0){
                    if (cnt[j] + 1 > cnt[i]){
                        cnt[i] = cnt[j] + 1;
                        pre[i] = j;
                    }
                }
            }
        }

        int largest_i = 0;
        for(int i = 0; i < n; i++){
            if (cnt[largest_i] < cnt[i]) largest_i = i;
        }
        while(largest_i != -1){
            ret.push_back(nums[largest_i]);
            largest_i = pre[largest_i];
        }
        return ret;
    }
};



int main() {
    Solution s1;
    auto ans = s1.superPow()
    //showV(ans);
    cout << ans << endl;
}
