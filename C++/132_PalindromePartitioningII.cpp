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

typedef pair<int, int> PII;

class Solution {
public:
    // 132. Palindrome Partitioning II
    // DP dp[i + l + 1] = min(dp[i + l + 1], dp[i - l] + 1);
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, s.size());
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            // center i;
            int l = 0;
            while(i - l >= 0 && i + l < n && s[i - l] == s[i + l]){
                dp[i + l + 1] = min(dp[i + l + 1], dp[i - l] + 1);
                l++;
            }
            // center i, i + 1;
            l = 0;
            while(i - l >= 0 && i + 1 + l < n && s[i - l] == s[i + 1 + l]){
                dp[i + 1 + l + 1] = min(dp[i + 1 + l + 1], dp[i - l] + 1);
                l++;
            }
        }
        return dp[n] - 1;
    }
};

int main() {
    Solution s1;
    string s = "aab";
    auto result = s1.minCut(s);
    cout << result << endl;
    //show(result);
}
