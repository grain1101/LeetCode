#include "leetcode.h"
class Solution {
public:
    // 237. Delete Node in a Linked List
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
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
