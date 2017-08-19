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
#include <set>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    // 123. Best Time to Buy and Sell Stock III
    // prices[0..A..i: i+1..B..n-1]
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        if (n == 0) return ans;
        int minA = INT_MAX;
        int maxA = INT_MIN;
        int maxB = INT_MIN;
        int maxVB = INT_MIN;
        vector<int> leftA(n, 0);
        vector<int> rightB(n, 0);
        for(int i = 0; i < n; i++){
            minA = min(minA, prices[i]);
            maxA = max(prices[i] - minA, maxA);
            leftA[i] = maxA;
        }
        for(int i = n - 1; i >= 0; i--){
            maxB = max(maxB, prices[i]);
            maxVB = max(maxB - prices[i], maxVB);
            rightB[i] = maxVB;
        }
        showV(leftA);
        showV(rightB);
        for(int i = 0; i < n; i++){
            ans = max(ans, leftA[i] + rightB[i]);
        }
        return ans;
    }
};


int main() {
    Solution s1;
    vector<int> nums = {7,1,5,3,6,4};
    auto result = s1.maxProfit(nums);







}
