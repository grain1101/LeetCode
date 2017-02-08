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
    // 28. Implement strStr()
    // Input: [3,2,2,3], 3
    // Output: the index of the first occurrence of needle in haystack,
    //          or -1 if needle is not part of haystack.
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        if (needle.size()==0) return 0;
        for(int i=0;i<haystack.size()-needle.size()+1;i++){
            bool flag = true;
            for(int j=0;j<needle.size();j++){
                if (j+i<haystack.size() && haystack[j+i] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return i;
        }
        return -1;
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
