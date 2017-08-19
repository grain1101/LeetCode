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
    // 26. Remove Duplicates from Sorted Array
    // Input: [1,1,2]
    // Output: 2
    // In place
    int removeDuplicates(vector<int>& nums) {
        int result = 0;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            nums[result++] = nums[i];
        }
        return result;
    }
};

int main() {
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {1, 1, 2};
    string s = "()[[]{}";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(0);
    ListNode *p = head;
//    for(int i=1;i<=5;i++){
//        head->next = new ListNode(i);
//        head = head->next;
//    }
    int n = 3;
    vector<ListNode*> lists;

    // 2. Run
    Solution s1;
    auto result = s1.removeDuplicates(nums);
    // 3. Compare output
//    for(auto n : result) {
//        for(auto num : n) {
//            cout << num << " ";
//        }
//        cout << endl;
//    }
    cout << result << endl;
    return 0;
}
