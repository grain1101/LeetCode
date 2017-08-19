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
  public:
    // 82. Remove Duplicates from Sorted List II
    // [1,1,1,2,3], return [2,3]
    // [1,2,3,3,4], return [1,2,4]
    // [1,2,3,3,3], return [1,2]
    // [1,1,2,2,2] return []
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newhead = new ListNode(-1);
        newhead->next = head;
        ListNode* p = newhead;
        ListNode* q = newhead->next;
        while(q && q->next){
            if (q->val == q->next->val){
                q = q->next;
                continue;
            }
            if (q->val != q->next->val){
                if (p->next != q){
                    q = q->next;
                    if (q && q->next && q->val == q->next->val){
                        q = q->next;
                        continue;
                    }
                }
                    p->next = q;
                    p = p-> next;
                    q = q-> next;
            }
        }
        if (p->next != q) p->next = nullptr;
        return newhead->next;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    Solution s1;
    auto result = s1.deleteDuplicates();
    cout << result << endl;
    return 0;
}
