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
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t;
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
    // 86. Partition List
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;
        ListNode *newhead = new ListNode(-1);
        newhead->next = head;
        ListNode *p = newhead, *q = p->next;
        ListNode *newtail = p;
        while(q){
            if (q->val < x){
                if (p == newhead || p == newtail) {
                    newtail = newtail->next;
                    p = p->next;
                    q = p->next;
                    continue;
                }
                ListNode *tmp = newtail->next;
                newtail->next = q;
                newtail = newtail->next;
                p->next = q->next;
                newtail->next = tmp;
                q = p->next;
            } else {
                p = p->next;
                q = p->next;
            }
        }
        return newhead->next;
    }
};

int main() {
    vector<int> nums = {2,1,5,6,2,3};
    Solution s1;
    auto result = s1.largestRectangleArea(nums);
    cout << result << endl;
    return 0;
}
