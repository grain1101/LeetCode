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
    // 139. Word Break
    // DP
    // s = "leetcode",
    // dict = ["leet", "code"].
    // The optimization is to look from current position i back and only substring and
    // do dictionary look up in case the preceding position j with dp[j] == true is found.
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> dict;
        for(int i = 0; i < wordDict.size(); i++){
            dict[wordDict[i]]++;
        }
        vector<bool> dp(s.size() + 1, false);
        for(int i = 1; i <= s.size(); i++){
            for(int j = i - 1; j >=0; j--){
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    Solution s1;
    cout << endl;
}
