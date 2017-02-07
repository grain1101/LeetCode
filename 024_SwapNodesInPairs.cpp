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
    // 24. Swap Nodes in Pairs
    // Input: 1->2->3->4
    // Output: 2->1->4->3
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *k, *p, *q;
        k = newHead;
        p = head;
        q = head->next;
        for(;q!=nullptr;k=p,p=p->next,q=p?p->next:nullptr){
            k->next = q;
            p->next = q->next;
            q->next = p;
        }
        return newHead->next;
    }
};

int main() {
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    string s = "()[[]{}";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(1);
    int n = 3;
    vector<ListNode*> lists;

    // 2. Run
    Solution s1;
    auto result = s1.mergeKLists(lists);
    // 3. Compare output

//    for(auto n : result) {
//        for(auto num : n) {
//            cout << num << " ";
//        }
//        cout << endl;
//    }
//    cout << result << endl;
    return 0;
}
