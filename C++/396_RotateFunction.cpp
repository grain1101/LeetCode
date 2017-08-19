#include "leetcode.h"

// 396. Rotate Function
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() == 0) return 0;
        long long f0 = 0, sum = 0;
        int n = A.size();
        for(int i = 0; i < n; i++){
            f0 += A[i] * i;
            sum += A[i];
        }

        long long ret = f0;
        for(int i = 0; i < n; i++){
            f0 -= sum;
            f0 += A[i] * n;
            ret = max(ret, f0);
        }
        return ret;
    }
};


int main() {
    Solution s1;
    vector<int> nums = {2147483647,2147483647};
    auto ans = s1.maxRotateFunction(nums);
    cout << ans << endl;
}
