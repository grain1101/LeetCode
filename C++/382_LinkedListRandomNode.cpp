#include "leetcode.h"

// 382. Linked List Random Node
// reservoir sampling
// same as 398;
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *head;
    Solution(ListNode* head) {
        srand(time(NULL));
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int ret = head->val;
        int i = 2;
        ListNode *node = head->next;
        while(node){
            int j = rand() % i;
            if (j == 0){
                ret = node->val;
            }
            i++;
            node = node->next;
        }
        return ret;
    }
};


int main() {
    vector<int> nums = {1,2,3,4};
    Solution *s1 = new Solution(nums);
    auto ans = s1->shuffle();
    showV(ans);
    //cout << ans << endl;
}
