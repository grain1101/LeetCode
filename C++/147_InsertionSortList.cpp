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
    // 147. Insertion Sort List
    // Insertion Sort Algorithm
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *newhead = nullptr, *newtail = nullptr;
        for(ListNode *p = head, *q = head; p; p = q){
            q = p->next;
            if (newhead == nullptr){
                newhead = p;
                newhead->next = nullptr;
                newtail = newhead;
            }
            else {
                // sorted sub-list [newhead, body, newtail]
                // newhead
                if (newhead->val >= p->val){
                    p->next = newhead;
                    newhead = p;
                    continue;
                }
                // newtail
                if (newtail->val <= p->val){
                    newtail->next = p;
                    newtail = newtail->next;
                    newtail->next = nullptr;
                    continue;
                }
                // body
                for(ListNode *k = newhead, *prek = newhead; k; prek = k, k = k ->next){
                    if (k->val > p->val){
                        prek->next = p;
                        p->next = k;
                        break;
                    }
                }
            }
        }
        return newhead;
    }
};

int main() {
    Solution s1;

}
