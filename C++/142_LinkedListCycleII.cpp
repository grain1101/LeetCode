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
    // 142. Linked List Cycle II
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode *fast = head->next->next , *slow = head->next ;
        for(;fast && fast->next; fast = fast->next->next, slow = slow->next){
            if (fast == slow) break;
        }
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        for(ListNode *p = head; p != slow; p = p->next, slow = slow->next);
        return slow;
    }
};

int main() {
    Solution s1;
    cout << endl;
}
