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
    // 25. Reverse Nodes in k-Group
    // Input: 1->2->3->4->5
    // Output:  k = 2:2->1->4->3->5; k=3:3->2->1->4->5
    // use temp vector to store node values. O(k)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k<2) return head;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *p,*q, *tail;
        p=head, q=head, tail=head;
        while(tail){
            for(int i=0;i<k;i++){
                tail = tail?tail->next:nullptr;
            }
            vector<int> v;
            for(int i=0;i<k;i++){
                if(q){
                    v.push_back(q->val);
                    q = q->next;
                }
            }
            if(v.size()==k){
                for(int i=v.size()-1;i>=0;i--){
                    if(p){
                        p->val = v[i];
                        p=p->next;
                    }
                }
            }
        }
        return newHead->next;
    }
};s

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
