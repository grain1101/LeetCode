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

 struct TreeNode {
    int val;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Solution {
public:
    // 191. Number of 1 Bits
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            ans += (n >> i) & 1;
        }
        return ans;
    }
    int hammingWeight2(uint32_t n) {
        // n & (n - 1)
        int cnt = 0;
        while (n) {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,4,5};
    uint32_t n = 7;
    auto ans = s1.hammingWeight(n);
    cout << ans << endl;
}
