#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // 88. Merge Sorted Array
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m - 1;
        int q = n - 1;
        for (int i = m + n; i >= 0; i--){
            nums1[i] = nums1[p] > nums2[q] ? nums1[p--] : nums2[q--];
        }
        return ;
    }
};


int main() {
    cout << mixed("abc", "abb", "abbabc") << endl;
    cout << mixed("abc", "abb", "ababbc") << endl;
}
