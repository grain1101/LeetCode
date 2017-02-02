#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 21. Merge Two Sorted Lists
    // input: {1,2,4,6,8} {3,4,5,6,8}
    // output: true;false;true;
    // Solutions: Stack;
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    }
};

int main()
{
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    string s = "()[[]{}";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(1);
    int n = 1;

    // 2. Run
    Solution s1;
    auto result = s1.isValid(s);
    // 3. Compare output

//    for(auto n : result){
//        for(auto num : n){
//            cout << num << " ";
//        }
//        cout << endl;
//    }
    cout << result << endl;
    return 0;
}
