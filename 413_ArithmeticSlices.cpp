#include "leetcode.h"

// 413. Arithmetic Slices
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int ret = 0, i = 2, j = 0, distance = A[1] - A[0];
        for(; i <= A.size(); i++){
            if (i < A.size() && A[i] - A[i - 1] == distance) continue;
            int len = i - j;
            if (len >= 3){
                for(int k = len - 2; k >= 0; k--) ret += k;
            }
            j = i - 1;
            if (i < A.size()) distance = A[i] - A[i - 1];
        }
        return ret;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,5,7,14,21};
    auto ans = s1.numberOfArithmeticSlices(nums);
    cout << ans << endl;
}
