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
    // 154. Find Minimum in Rotated Sorted Array II
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums.size() == 1) return nums[0];
        if (nums[l] < nums[r]) return nums[l];
        while(l + 1 < r){
            int mid = l + (r - l) / 2;
            if (nums[r] < nums[mid]) l = mid;
            else if (nums[r] > nums[mid]) r = mid;
            else {
                //if (nums[l] == nums[mid]) l++;
                if (nums[r] == nums[mid]) r--;
            }
        }
        return nums[l + 1];
    }
};

int main() {
    Solution s1;
    vector<int> nums = {3, 3, 1};
    auto r = s1.findMin(nums);
    cout << r << endl;
}
