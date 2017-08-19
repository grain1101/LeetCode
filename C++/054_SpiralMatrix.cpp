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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
    // 54. Spiral Matrix
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return {};
        int n = matrix[0].size();
        vector<int> ans(m * n);
        int p = 0;
        int x1 = 0;
        int y1 = 0;
        int x2 = m - 1;
        int y2 = n - 1;
        while(x1 <= x2 && y1 <= y2){
            if(x1 == x2 || y1 == y2){
                if(x1 == x2)
                    for(int i = y1; i <= y2; i++) ans[p++] = matrix[x1][i];
                if(y1 == y2){
                    for(int i = x1; i <= x2; i++) ans[p++] = matrix[i][y1];
                }
            } else{
                for(int i = y1; i < y2; i++) ans[p++] = matrix[x1][i];
                for(int i = x1; i < x2; i++) ans[p++] = matrix[i][y2];
                for(int i = y2; i > y1; i--) ans[p++] = matrix[x2][i];
                for(int i = x2; i > x1; i--) ans[p++] = matrix[i][y1];
            }
            x1++;
            y1++;
            x2--;
            y2--;
        }
        return ans;
    }
};


int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    auto result = s1.totalNQueens(8);
//    for(auto r : result){
//        for(auto t : r){
//            cout << t<<endl;
//        }
//        cout << endl;
//    }
    cout << result << endl;
    return 0;
}
