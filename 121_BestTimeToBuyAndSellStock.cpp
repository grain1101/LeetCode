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
    // 121. Best Time to Buy and Sell Stock
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if (prices.size() == 0) return 0;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++){
           if (prices[i] < minPrice) minPrice = prices[i];
           ans = max(ans, prices[i] - minPrice);
        }
        return ans;
    }
};


int main() {
    Solution s1;
    auto result = s1.getRow(5);
    for(auto r : result)
        cout << r << " ";
    cout << endl;
}
