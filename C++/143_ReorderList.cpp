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
#include <cassert>
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
    // 143. Reorder List
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode *newhead = nullptr, *newtail = nullptr;
        // 1. divide list as two part: head, second;
        ListNode *fast = head, *slow = head;
        for(;fast->next && fast->next->next; slow = slow->next, fast = fast->next->next);
        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode *secondNext = second;
        // 2. reverse second
        while(second != nullptr){
            secondNext = second->next;
            if (newhead == nullptr){
                newhead = newtail = second;
                newtail->next = nullptr;
            } else {
                second->next = newhead;
                newhead = second;
            }
            second = secondNext;
        }
        // 3. merge head and second
        for(ListNode *p = head;p,newhead;p = p->next->next){
            ListNode *tmp = newhead->next;
            newhead->next = p->next;
            p->next = newhead;
            newhead = tmp;
        }
        return;
    }
};

int main() {
    Solution s1;
    ListNode *head, *p;
    head = new ListNode(0);
    p = head;
    for(int i = 1; i <= 6; i++){
        p->next = new ListNode(i);
        p = p->next;
    }
    s1.reorderList(head->next);
    while(head){
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}
