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
    // 33. Search in Rotated Sorted Array
    // Input:  4 5 6 7 0 1 2;
    // Output: 4; 6; 4
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        // find the smallest num's index
        while(l<r){
            int mid = (l + r) / 2;
            if(nums[mid] >  nums[r]) l = mid + 1;
            else r = mid;
        }
        int rot = l;
        l = 0, r = nums.size()-1;
        // The usual binary search and accounting for rotation
        while(l<=r){
            int mid = (l + r) / 2;
            int realMid = (mid + rot) % nums.size();
            if(nums[realMid] == target) return realMid;
            if(nums[realMid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};

int main() {
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {2,3,4,1};
    string ss = "))))()";
    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(0);
    ListNode *p = head;
    int n = 3;
    vector<ListNode*> lists;

    // 2. Run
    Solution s1;
    auto result = s1.search(nums,1);
    // 3. Compare output
//    for(auto i : result){
//        cout << i << " ";
//    }
//    cout << endl;
    cout << result << endl;
    return 0;
}
