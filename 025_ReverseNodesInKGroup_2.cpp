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
    // 25. Reverse Nodes in k-Group
    // Input: 1->2->3->4->5
    // Output:  k = 2:2->1->4->3->5; k=3:3->2->1->4->5
    // use temp vector to store node values. O(k)
    void insertNodeAfterTail(ListNode *&cur, ListNode *&tail){
        ListNode *tmp = cur->next;
        ListNode *tailNext = tail->next;
        tail->next = cur;
        cur->next = tailNext;
        cur = tmp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k<2) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = head;
        ListNode *tail = dummy;
        ListNode *nextTail;
        for(int index=1;cur;index++) {
            if (index%k == 1) {
                nextTail = cur;
            }
            insertNodeAfterTail(cur, tail);
            if (index%k == 0) {
                tail = nextTail;
            }
        }
        // reverse the last n%k nodes.
        // 4 3 2 1 5 6
        cur = tail->next;
        tail->next = nullptr;
        while(cur){
            insertNodeAfterTail(cur, tail);
        }
        return dummy->next;
    }
};

int main() {
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    string s = "()[[]{}";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(0);
    ListNode *p = head;
    for(int i=1;i<=5;i++){
        head->next = new ListNode(i);
        head = head->next;
    }
//    while(p){
//        cout << p->val << " ";
//        p = p->next;
//    }
//    cout << endl;
    int n = 3;
    vector<ListNode*> lists;

    // 2. Run
    Solution s1;
    auto result = s1.reverseList(p->next);
    // 3. Compare output
    while(result){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
//    for(auto n : result) {
//        for(auto num : n) {
//            cout << num << " ";
//        }
//        cout << endl;
//    }
//    cout << result << endl;
    return 0;
}
