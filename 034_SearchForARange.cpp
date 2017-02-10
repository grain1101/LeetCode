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
    // 34. Search for a Range
    // Input:  [5, 7, 7, 8, 8, 10], 8;9
    // Output: [3, 4];[-1, -1]
    // runtime complexity must be in the order O(logN);
    // Break down as two binary search for the begining and end of the range.
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0 || target < nums[0] || target > nums[nums.size() - 1]) return {-1, -1};
        vector<int> result(2, -1);
        // search for the left begining range
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if(nums[l] != target) return result;
        else result[0] = l;

        // search for the right end range
        r = nums.size()-1;
        while(l < r){
            int mid = (l + r + 1)/2;
            if(nums[mid] > target) r = mid -1;
            else l = mid;
        }
        result[1] = r;
        return result;
    }
};

int main() {
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {1,1,1,1,1};
    string ss = "))))()";
    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(0);
    ListNode *p = head;
    int n = 3;
    vector<ListNode*> lists;

    // 2. Run
    Solution s1;
    auto result = s1.searchRange(nums, 1);
    // 3. Compare output
//    for(auto i : result){
//        cout << i << " ";
//    }
//    cout << endl;
//    cout << result << endl;
    return 0;
}
