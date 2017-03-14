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
    // 153. Find Minimum in Rotated Sorted Array
    // 4 5 6 7 0 1 2 -> 0
    // binary search
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] <= nums[r]) return nums[l];
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if (nums[l] < nums[mid]) l = mid;
            else r = mid;
        }
        return nums[l + 1];
    }
};

int main() {
    Solution s1;
    vector<int> nums = {0};
    auto r = s1.findMin(nums);
    cout << r << endl;
}
