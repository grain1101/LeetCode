#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <set>
#include <string>
#include<list>
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
        cout << r << " ";
    cout << endl;
}
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // 234. Palindrome Linked List
    // 1. find list mid with fast and slow
    // 2. reverse [0,mid);
    // 3. compare[0,mid),[mid+1,end]
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // now slow is list mid;
        head = reverseList(head, slow);
        while(slow && head){
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head, ListNode* slow){
        ListNode *dummy = new ListNode(-1);
        while(head != slow){
            ListNode * next = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = next;
        }
        return dummy->next;
    }
};


int main() {
    Solution s1;
    int n = 3;
    auto ans = s1.isPalindrome(nullptr);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
