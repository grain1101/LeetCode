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

class Solution {
public:
    // 97. Interleaving String
    // Memo Search
    bool isMixed(int x, int y){
        // cout << x << " " << y << endl;
        if (x >= s1.size()) {
            return (s3.substr(x + y) == s2.substr(y));
        }
        if (y >= s2.size()){
            return (s3.substr(x + y) == s1.substr(x));
        }

        int &ans = dp[x][y];
        if (ans != -1) return ans;

        return ans = ((s3[x + y] == s1[x] && isMixed(x + 1, y)) ||
                      (s3[x + y] == s2[y] && isMixed(x, y + 1)));
    }
    bool isInterleave(string _s1, string _s2, string _s3) {

        s1 = _s1; s2 = _s2; s3 = _s3;
        int n = s1.size();
        int m = s2.size();
        if (n + m != s3.size()) return false;
        if (n == 0) return (s2 == s3);
        if (m == 0) return (s1 == s3);
        dp.assign(n, vector<int>(m, -1));
        return isMixed(0, 0);
    }

private:
    vector<vector<int>> dp;
    string s1;
    string s2;
    string s3;
};




int main() {
    Solution s1;
    string str1 = "aabcc";
    string str2 = "dbbca";
    string str3 = "aadbbcbcac";
    auto result = s1.isInterleave(str1, str2, str3);
    cout << result << endl;
}
