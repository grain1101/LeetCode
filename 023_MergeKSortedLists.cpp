#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 23. Merge k Sorted Lists
    // Solution: Heap; priority_queue
    struct ListNodeCmp {
        bool operator()(ListNode* const& a, ListNode* const& b) const {
            return a->val > b->val;
        }
    };
    void addListNode(ListNode*& head, ListNode*& tail, ListNode* const& curMin){
        if (head==nullptr) {
            head = tail = curMin;
        } else {
            tail->next = curMin;
            tail = tail->next;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> pq;
        for(int i=0; i<lists.size(); i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while(pq.size()) {
            ListNode *curMin = pq.top();
            addListNode(head, tail, curMin);
            pq.pop();
            if (curMin->next) {
                pq.push(curMin->next);
            }
        }
        return head;
    }
};

int main() {
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    string s = "()[[]{}";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(1);
    int n = 3;
    vector<ListNode*> lists;

    // 2. Run
    Solution s1;
    auto result = s1.mergeKLists(lists);
    // 3. Compare output

//    for(auto n : result) {
//        for(auto num : n) {
//            cout << num << " ";
//        }
//        cout << endl;
//    }
//    cout << result << endl;
    return 0;
}
