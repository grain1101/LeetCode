#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
}

class Solution {
  public:
    // 73. Set Matrix Zeroes
    // 用matrix的第0行和第0列用来代替row[],col[],空间复杂度降为constant。另外需要两个临时便令记录第0行和第0列是否置为0
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 1, col = 1;
        for(int i = 0; i < n; i++){
            if (matrix[i][0] == 0){
                col = 0;
                break;
            }
        }
        for(int j = 0; j < m; j++){
            if (matrix[0][j] == 0) {
                row = 0;
                break;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // set row [i:1...m-1] as 0
        for(int i = 1; i < n; i++){
            if (matrix[i][0] == 0){
                for(int j = 1; j < m; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        // set col [1...n-1:j] as 0
        for(int j = 1; j < m; j++){
            if (matrix[0][j] == 0) {
                for(int i = 1; i < n; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        // first col
        if (col == 0) {
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
        // first row
        if (row == 0) {
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }
        return;
    }
};

int main() {
    Solution s1;
    auto result = s1.minDistance("azced", "abcdef");
    cout << result << endl;
    return 0;
}
