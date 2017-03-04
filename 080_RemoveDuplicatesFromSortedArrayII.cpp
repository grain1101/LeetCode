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
    // 80. Remove Duplicates from Sorted Array II
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int index = 2;
        for(int i = 2; i < nums.size(); i++){
            if (nums[i] != nums[index - 2]){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    Solution s1;
    auto result = s1.removeDuplicates(nums);
    for(auto n : nums) cout << n ;
    cout << endl;
    cout << result << endl;
    return 0;
}
