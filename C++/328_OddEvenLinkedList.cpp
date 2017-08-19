#include "leetcode.h"

class Solution {
public:
    // 328. Odd Even Linked List
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode *p = head, *tail = head->next, *q = tail;
        while(q && q->next){
            p->next = p->next->next;
            q->next = q->next->next;
            p = p->next;
            q = q->next;
        }
        p->next = tail;
        return head;
    }
};

int main() {
    Solution s1;
    ListNode *head = nullptr;
    auto ans = s1.oddEvenList(head);
    //cout << ans << endl;
}
