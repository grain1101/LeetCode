#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 2. Add Two Numbers
    // Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    // Output: 7 -> 0 -> 8
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int carry = 0;
        while(l1 || l2){
            int var1 = 0;
            int var2 = 0;
            if(l1){
                var1 = l1->val;
                l1 = l1->next;
            }
            if(l2){
                var2 = l2->val;
                l2 = l2->next;
            }
            int sum = var1 + var2 + carry;
            carry = sum/10;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
        }
        if(carry==1){
            tail->next = new ListNode(1);
        }
        return head->next;
    }
};

int main()
{
    // 1. Input test cases
    ListNode* l1 = new ListNode(-1);
    ListNode* l2 = new ListNode(-1);
    ListNode* p = l1;
    ListNode* q = l2;
    int a[3] = {2, 4, 3};
    int b[3] = {5, 6, 4};

    for(int i=0;i<3;i++){
        l1->next = new ListNode(a[i]);
        l1 = l1->next;
        l2->next = new ListNode(b[i]);
        l2 = l2->next;
    }

    // 2. Run
    Solution s1;
    auto result = s1.addTwoNumbers(p->next, q->next);

    // 3. Compare output
    while(result){
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
