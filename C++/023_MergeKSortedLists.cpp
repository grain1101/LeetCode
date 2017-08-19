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

