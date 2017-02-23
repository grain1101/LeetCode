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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
}

class Solution {
  public:
    // 61. Rotate List
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        // 0,        1, 2, 3, 4
        // newhead   qq,q,    pp, p
        ListNode *p= newhead, *q = newhead, *pp = newhead, *qq = newhead;
        int n = 0;
        ListNode *tmp = head;
        while(tmp){
            n++;
            tmp = tmp->next;
        }
        if(n == 0 || k % n == 0) return head;
        k = k % n;
        while(k--){
            p = p->next;
        }
        while(p){
            pp = p;
            p = p->next;
            qq = q;
            q = q->next;
        }
        qq->next = nullptr;
        pp->next = head;
        return q;
    }
};


int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for(int i = 1;i <= 4; i++){
        p->next = new ListNode(i);
        p = p->next;
    }
    Solution s1;
    auto result = s1.rotateRight(head->next, 0);
    for(; result; result = result->next){
        cout << result->val;
    }
    cout << endl;
//    cout << result << endl;
    return 0;
}
