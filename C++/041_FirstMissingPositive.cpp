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
    // 41. First Missing Positive
    int firstMissingPositive(vector<int>& nums) {
      //if (nums.size()==0) return 1;
      for(int i=0;i<nums.size();i++){
          //if (i+1 == nums[i]) continue;
          int x = nums[i];
          while(x>=1 && x<=nums.size() && x!=nums[x-1]){
              swap(x, nums[x-1]);
          }
      }
      for(int i=0;i<nums.size();i++){
          if(nums[i]!=i+1) return i+1;
      }
      return nums.size()+1;
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
