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

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    // 138. Copy List with Random Pointer
    // head: 1->2->3->4
    // copyNext: 1->1'->2->2'->3->3'->4->4'
    // copyRandom
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) return head;
        // copy next
        for(RandomListNode *p = head; p; p = p->next){
            RandomListNode *newP = new RandomListNode(p->label);
            newP->next = p->next;
            p->next = newP;
            p = p->next;
        }
        // copy random
        for(RandomListNode *p = head; p; p = p->next){
            if (p->random){
                p->next->random = p->random->next;
            }
            p = p->next;
        }
        // generate new list
        RandomListNode *newhead = nullptr, *tail = nullptr;
        for(RandomListNode *p = head; p; p = p->next){
            if (newhead == nullptr){
                newhead = tail = p->next;
            } else {
                tail->next = p->next;
                tail = tail->next;
            }
            p->next = p->next->next;
        }
        return newhead;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,1,1,1,2,2,2,2,3,3,3,3,4};
    auto r = s1.singleNumber(nums);
    cout << r << endl;
}
