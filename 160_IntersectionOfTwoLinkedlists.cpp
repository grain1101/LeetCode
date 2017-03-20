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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // 160. Intersection of Two Linked Lists
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        int lenA = 0, lenB = 0;
        for(ListNode *p = headA; p; p=p->next){
            lenA++;
        }
        for(ListNode *p = headB; p; p=p->next){
            lenB++;
        }
        ListNode *first, *second;
        int len = 0;
        if (lenA > lenB) {
            first = headA;
            second = headB;
            len = lenA - lenB;
        } else {
            first = headB;
            second = headA;
            len = lenB - lenA;
        }
        while(len--){
            first = first->next;
        }
        for(;first && second; first=first->next, second=second->next){
            if (first == second) return first;
        }
        return nullptr;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,1,1,1,2,2,2,2,3,3,3,3,4};
    auto r = s1.singleNumber(nums);
    cout << r << endl;
}
