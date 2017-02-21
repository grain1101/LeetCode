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
    // 53. Maximum Subarray
    // [-2,1,-3,4,-1,2,1,-5,4]
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int tmp = dp[i - 1] + nums[i];
            dp[i] = max(nums[i], tmp);
        }
        int ans = INT_MIN;
        for(int i = 0; i < dp.size(); i++){
            ans = max(ans, dp[i]);
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
