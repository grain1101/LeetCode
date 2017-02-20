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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 48. Rotate Image
    void rotate(vector<vector<int>>& m) {
        int n = m.size();

        for(int i = 0; i < n/2 + n%2; i++){
            for(int j = 0; j < n/2; j++){
                int tmp = m[i][j];
                m[i][j] = m[n-j-1][i];
                m[n-j-1][i] = m[n-i-1][n-j-1];
                m[n-i-1][n-j-1] = m[j][n-i-1];
                m[j][n-i-1] = tmp;
            }
        }
    }
};

int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    auto result = s1.permuteUnique(nums);
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
//    cout << result << endl;
    return 0;
}
