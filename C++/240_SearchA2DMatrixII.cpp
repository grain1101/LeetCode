#include "leetcode.h"
class Solution {
public:
    // 240. Search a 2D Matrix II
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int i = 0;
        int j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0){
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) j--;
            if (matrix[i][j] < target) i++;
        }
        return false;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,4};

    auto ans = s1.searchMatrix(matrix, target);
    //cout << ans << endl;
    showV(ans);
    //show(ans);
    //showV(ans);
}
