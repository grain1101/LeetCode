#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 19. Remove Nth Node From End of List
    // input: 1->2->3->4->5;2
    // output: 1->2->3->5.
    // Solutions: two pointers
    // Notice [1], 1; [1,2], 2;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *l = new ListNode(0);
        l->next = head;
        ListNode *newHead = l;
        ListNode *r = l;
        if(head==nullptr ||head->next==nullptr) return nullptr;
        for(int i=0;i<n;i++){
            if(r){
                r=r->next;
            }else{
                return newHead->next;
            }
        }
        while(r && r->next){
            l=l->next;
            r=r->next;
        }
        if(r && l->next) l->next = l->next->next;
        return newHead->next;
    }
};

int main()
{
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    string s = "23";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(1);
    int n = 1;

    // 2. Run
    Solution s1;
    auto result = s1.removeNthFromEnd(head,n);
    // 3. Compare output
    while(result){
        cout << result->val << " ";
    }
    cout << endl;
//    for(auto n : result){
//        for(auto num : n){
//            cout << num << " ";
//        }
//        cout << endl;
//    }
//    cout << result << endl;
    return 0;
}
