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
    // 81. Search in Rotated Sorted Array II
    bool search(vector<int>& nums, int target) {

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
