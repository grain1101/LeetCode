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
#include <cassert>
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
    // 164. Maximum Gap
    int getMaxNum(const vector<int> &nums){
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, nums[i]);
        }
        return ans;
    }
    vector<int> countSort(const vector<int> &nums, int exp){
        vector<int> ans(nums.size(), 0);
        // count how many 0,1,2... on exp bits
        vector<int> counts(D, 0);
        for(int i = 0; i < nums.size(); i++){
            counts[nums[i] / exp % D]++;
        }
        for(int i = 1; i < D; i++){
            counts[i] += counts[i - 1];
        }
        // search from right to left
        for(int i = nums.size() - 1; i >= 0; i--){
            int bits = nums[i] / exp % D;
            ans[--counts[bits]] = nums[i];
        }
        return ans;
    }
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int maxNum = getMaxNum(nums);
        for(int i = 1; i <= maxNum; i *= D){
            nums = countSort(nums, i);
            //showV(nums);
        }

        int ans = INT_MIN;
        for(int i = 1; i < nums.size(); i++){
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
private:
    const int D = 10;
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,5,4,7};
    auto r = s1.maximumGap(nums);
    cout << r << endl;
}
