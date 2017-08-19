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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // 209. Minimum Size Subarray Sum
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = INT_MAX;
        int sum = 0;
        int p = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= s){
                ans = min(ans, i - p + 1);
                sum -= nums[p++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};



int main() {
    Solution s1;
    vector<int> nums = {10,2,3};
    auto ans = s1.minSubArrayLen(6, nums);
    cout << ans << endl;
}
