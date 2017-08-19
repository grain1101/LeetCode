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
    // 162. Find Peak Element
    int findPeakElement(vector<int>& num) {
        int l = 0, r = num.size() - 1;
        while(l < r){
            int mid = (l + r) / 2;
            int mid2 = mid + 1;
            if (num[mid] < num[mid2]) l = mid2;
            else r = mid;
        }
        return l;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,1,1,1,2,2,2,2,3,3,3,3,4};
    auto r = s1.singleNumber(nums);
    cout << r << endl;
}
