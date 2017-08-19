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
    // 74. Search a 2D Matrix
    // Binary Search
    // matrix[i][j] => a[i * n + j];
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if(n==0) return false;
        int m = matrix[0].size();
        if(m == 0) return false;
        if(target<matrix[0][0]||target>matrix[n-1][m-1]) return false;
        if(target==matrix[0][0]||target==matrix[n-1][m-1]) return true;
        int l=0,r=m*n-1;
        while(l+1<r){
            int mid=(l+r)/2;
            if(matrix[mid/m][mid%m]<target) l=mid;
            else r=mid;
        }
        return (matrix[r/m][r%m]==target);
    }
};

int main() {
    cout << 1%2 << endl;
    Solution s1;
    //auto result = s1.minDistance("azced", "abcdef");
    //cout << result << endl;
    return 0;
}
