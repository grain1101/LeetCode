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
    // 27. Remove Element
    // Input: [3,2,2,3], 3
    // Output: 2
    // In place
    int removeElement(vector<int>& nums, int val) {
        int result = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val) continue;
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
