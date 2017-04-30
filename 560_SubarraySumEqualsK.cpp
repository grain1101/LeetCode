#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <set>
#include <string>
#include<list>
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
        cout << r << " ";
    cout << endl;
}

class Solution {
public:
    // 560. Subarray Sum Equals K
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        if (nums.size() == 0) return ans;
        vector<int> preSum(nums.size());
        preSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            preSum[i] = preSum[i - 1] + nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            if (preSum[i] == k) ans++;
            if (i > 0){
                int p = 0;
                while(p < i){
                    if (preSum[i] - preSum[p] == k) ans ++;
                    p++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,1,1};
    int k = 2;
    auto ans = s1.subarraySum(nums, k);
    cout << ans << endl;
    //show(ans);
    //showV(ans);
}
