#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 35. Search Insert Position
    // Input:  [1,3,5,6], 5 -> 2
    // ->      [1,3,5,6], 2 -> 1
    // Output: [1,3,5,6], 7 -> 4
    //         [1,3,5,6], 0 -> 0
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        if(target <= nums[0]) return 0;
        if(target > nums[nums.size()-1]) return nums.size();
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};

int main() {
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {1,3,5,6};
    string ss = "))))()";
    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(0);
    ListNode *p = head;
    int n = 3;
    vector<ListNode*> lists;

    // 2. Run
    Solution s1;
    auto result = s1.searchInsert(nums, 0);
    // 3. Compare output
//    for(auto i : result){
//        cout << i << " ";
//    }
//    cout << endl;
    cout << result << endl;
    return 0;
}
