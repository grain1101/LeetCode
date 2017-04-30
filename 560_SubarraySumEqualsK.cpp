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
        int preSum = 0;
        unordered_map<int,int> hashSum;
        for(int i = 0; i < nums.size(); i++){
            preSum = preSum + nums[i];
            int tmp = preSum - k;
            if (tmp == 0) ans++;
            if (hashSum.find(tmp) != hashSum.end()) ans += hashSum[tmp];
            hashSum[preSum]++;
        }
        return ans;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,0,-1};
    int k = 0;
    auto ans = s1.subarraySum(nums, k);
    cout << ans << endl;
    //show(ans);
    //showV(ans);
}
