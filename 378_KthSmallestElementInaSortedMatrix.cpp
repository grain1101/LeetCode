#include "leetcode.h"

// 378. Kth Smallest Element in a Sorted Matrix
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix;
        n = m.size();
        if (n == 0) return 0;
        for(int i = 0; i < k - 1; i++){
             popup(0,0);
        }
        return m[0][0];
    }
private:
    vector<vector<int>> m;
    int n;
    void popup(const int i, const int j){
        if (i >= n || j >= n) return;
        int right = (j == n - 1) ? INT_MAX : m[i][j + 1];
        int down = (i == n - 1) ? INT_MAX : m[i + 1][j];
        m[i][j] = min(right, down);
        if (right == INT_MAX && down == INT_MAX) return;
        if (right < down)   popup(i, j + 1);
        else popup(i + 1, j);
    }
};

int main() {
    Solution s1;
    vector<vector<int>> nums = {{1,5,9},{10,11,13},{12,13,15}};
    auto ans = s1.kthSmallest(nums, 6);
    cout << ans << endl;
}
