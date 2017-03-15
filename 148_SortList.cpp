#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <set>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t << " ";
        }
        cout << endl;
    }
}
void showV(auto& result){
    for(auto r : result)
        cout << r;
    cout << endl;
}
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // 148. Sort List
    // Merge Sort Algorithm O(nlogn)
    // Step 1 - if it is only one element in the list it is already sorted, return.
    // Step 2 - divide the list recursively into two halves until it can no more be divided.
    // Step 3 - merge the smaller lists into new list in sorted order.
    ListNode* sortList(ListNode* head) {
        // Step 1.
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *p = head, *q = head->next;
        // p move 1 step; q move 2 step; to find the mid of the list
        for(;q->next && q->next->next;p=p->next, q = q->next->next);
        q = p->next;
        p->next = nullptr;
        // Step 2.
        p = sortList(head);
        q = sortList(q);
        ListNode *newhead = nullptr, *tail = nullptr;
        // Step 3.
        while(p || q){
            ListNode *tmp = nullptr;
            if (q == nullptr || (p && q->val >= p->val)){
                tmp = p;
                p = p->next;
            } else {
                tmp = q;
                q = q->next;
            }

            if (newhead == nullptr){
                newhead = tail = tmp;
                tail->next = nullptr;
            } else {
                tail->next = tmp;
                tail = tail->next;
                tail->next = nullptr;
            }
        }
        return newhead;
    }
};

int main() {
    Solution s1;

}
