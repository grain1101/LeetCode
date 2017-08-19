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
    // 75. Sort Colors
    // l: first not zero
    // r: first not two
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == 0 && i > l){
                swap(nums[i--], nums[l++]);
            }
            if (nums[i] == 2 && i < r){
                swap(nums[i--], nums[r--]);
            }
        }
    }
};

int main() {
    //{0,0,1,0,2,0,1,0,1,0,2,1};
    vector<int> nums = {2,0};
    for(auto n : nums){
        cout << n;
    }
    cout << endl;
    Solution s1;
    s1.sortColors(nums);
    for(auto n : nums){
        cout << n;
    }
    cout << endl;
    return 0;
}
