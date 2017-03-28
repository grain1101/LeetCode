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
    // 172. Factorial Trailing Zeroes
    int trailingZeroes(int n) {
        int ans = 0;
        while(n){
            ans += n/ 5;
            n /= 5;
        }
        return ans;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto r = s1.convertToTitle(28);
    cout << r << endl;
}
