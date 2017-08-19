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
        ListNode *p = headA, *q = headB;
        while(p ! = q){
            p = p ? p->next : headA;
            q = q ? q->next : headB;
        }
        return p;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,1,1,1,2,2,2,2,3,3,3,3,4};
    auto r = s1.singleNumber(nums);
    cout << r << endl;
}
