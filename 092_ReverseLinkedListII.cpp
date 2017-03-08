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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // 92. Reverse Linked List II
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m >= n) return head;
        ListNode* newhead = new ListNode(-1);
        newhead->next = head;
        ListNode *reverseHead = newhead, *reverseTail = newhead;
        ListNode *p;
        for(int i = 0; i < n && reverseTail->next; i++){
            if (i == m - 1) reverseHead = reverseTail;
            if (i == m) p = reverseTail;
            reverseTail = reverseTail->next;
        }
         //cout << reverseHead->val << " " << p->val << " " << reverseTail->val;
        // m = 2, n = 4;
        // reverseHead->val = 1, p->val = 2, reverseTail->val = 4;
        ListNode *q = reverseTail->next;
        while(p != reverseTail){
            ListNode *tmp = p->next;
            p->next = q;
            reverseTail->next = p;
            reverseHead->next = tmp;
            q = p;
            p = tmp;
        }

        return newhead->next;
    }
};




int main() {
    ListNode *head = new ListNode(-1);
    ListNode *p = head;
    for(int i = 1; i <= 8; i++){
        p->next = new ListNode(i);
        p = p->next;
    }

    Solution s1;
    auto result =  s1.reverseBetween(head->next, 8, 8);
    for(ListNode *p = result; p;p=p->next){
        cout << p->val << " ";
    }
    cout << endl;
    //cout << result << endl;
}
