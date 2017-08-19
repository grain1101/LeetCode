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
#include <set>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t << " ";
        }
        cout << endl;
    }
}
void showV(auto& result){
    for(auto r : result)
        cout << r;
    cout << endl;
}


class Solution {
public:
    // 152. Maximum Product Subarray
    // [2,3,-2,4] -> 2*3 = 6
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = INT_MIN;
        int tmp = 1;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == 0) {
                ans = max(ans, 0);
                tmp = 1;
                continue;
            }
            tmp = tmp * nums[i];
            ans = max(ans, tmp);

        }
        tmp = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if (nums[i] == 0) {
                ans = max(ans, 0);
                tmp = 1;
                continue;
            }
            tmp = tmp * nums[i];
            ans = max(ans, tmp);

        }
        return ans;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {-1,-1,3,-1,4};
    auto r = s1.maxProduct(nums);
    cout << r << endl;
}
