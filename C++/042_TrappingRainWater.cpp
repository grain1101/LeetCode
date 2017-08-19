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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 42. Trapping Rain Water
    // two pointers;
    int trap(vector<int>& height) {
        int result = 0;
        int maxLeft = 0, maxRight = 0;
        int left = 0, right = height.size()-1;
        while(left<=right){
            if (height[left] <= height[right]){
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    result += maxLeft - height[left];
                }
                left++;
            } else {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    result += maxRight - height[right];
                }
                right--;
            }
        }
        return result;
    }
};

int main() {
    // 1. Input test cases
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int n = 8;
    // 2. Run
    Solution s1;
    auto result = s1.combinationSum2(nums, n);

    // 3. Compare output
    for(auto i : result){
        for(auto t : i)
            cout << t << " ";
        cout << endl;
    }

//    cout << result << endl;
    return 0;
}
