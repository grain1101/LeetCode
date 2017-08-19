#include "leetcode.h"

class NumMatrix {
public:
    // 304. Range Sum Query 2D - Immutable
    NumMatrix(vector<vector<int>> _matrix) {
        matrix = _matrix;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 1; j < matrix[i].size(); j++){
                matrix[i][j] += matrix[i][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for(int i = row1; i <= row2; i++){
            ret += col1 == 0 ? matrix[i][col2] : matrix[i][col2] - matrix[i][col1 - 1];
        }
        return ret;
    }
private:
    vector<vector<int>> matrix;
};

int main() {

    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(nums);
    auto ans = obj->sumRange(0,5);
    cout << ans << endl;
//    showV(ans);
    //show(ans);
    //showV(ans);
}
