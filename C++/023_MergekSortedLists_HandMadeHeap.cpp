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
    struct priorityQueue{
      public:
        void show() {
            for(auto i : vpq){
                cout << i->val << " ";
            }
            cout << endl;
        }

        void push(ListNode* node){
            vpq.push_back(node);
            popUp(vpq.size()-1);
        }
        void pop(){
            swap(vpq[0], vpq[vpq.size()-1]);
            vpq.pop_back();
            sinkDown(0);
            return;
        }
        ListNode* top(){
            ListNode* topNode = nullptr;
            if (vpq.size()) {
                topNode = vpq[0];
            }
            return topNode;
        }
        int size() {
            return vpq.size();
        }
      private:
        vector<ListNode*> vpq;
        ListNodeCmp cmp;
        void makeMinHeap() {

        }
        void popUp(int i) {
            if (i==0) return;
            int father = (i-1)/2;
            if (cmp(vpq[father], vpq[i])) {
                swap(vpq[father], vpq[i]);
                popUp(father);
            }
            return;
        }
        void sinkDown(int i){
            int l = 2*i+1;
            int r = 2*i+2;
            if (l >= vpq.size()) return;
            if (l == vpq.size()-1) {
                if(cmp(vpq[i], vpq[l])) {
                    swap(vpq[i], vpq[l]);
                }
                return;
            }
            int tmp = cmp(vpq[l], vpq[r]) ? r : l;
            if (cmp(vpq[i], vpq[tmp])) {
                swap(vpq[i], vpq[tmp]);
                sinkDown(tmp);
            }
            return;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priorityQueue pq;
        for(int i=0; i<lists.size(); i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }

        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while(pq.size()) {
            //pq.show();
            ListNode *curMin = pq.top();
            addListNode(head, tail, curMin);
            pq.pop();
            //cout << "after pop:" << endl;
            //pq.show();
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
