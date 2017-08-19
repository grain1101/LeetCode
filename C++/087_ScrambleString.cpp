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
    // 87. Scramble String
    // Memo search
    // use dp to decrease time complex from O(n!) to O(n^4)
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n != s2.size()) return false;
        if (s1 == s2) return true;
        dp.assign(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return isScramble_(0, 0, n);
    }
private:
    int isScramble_(int s1, int s2, int len) {
        int &ans = dp[s1][s2][len];
        if (ans != -1) return ans;
        for(int i = 1; i < len; i++) {
            //not swapped
            if (isScramble_(s1, s2, i) && isScramble_(s1 + i, s2 + i, len - i)) return (ans = 1);
            // swapped
            if (isScramble_(s1, s2 + len - i, i) && isScramble_(s1 + i, s2, len - i)) return (ans = 1);
        }
        return (ans = 0);
    }
    vector<vector<vector<int>>> dp;
};

// Problem: give you three string str1 and str2 and str3.
// please determine whether str1 mixed str2 can generate str3.
// the characters sequence of str1 and str2 can't be changed.
// example: "abc", "abb" -> "abbabc"
vector<vector<int>> dp;
int f(int x, int y, const string& str1, const string& str2, const string& str3) {

    if (x >= str1.size() || y >= str1.size()) return true;

    int& ans = dp[x][y];
    if (ans != -1) return ans;

    return ans = (str3[x + y] == str1[x] && f(x + 1, y, str1, str2, str3)) ||
        (str3[x + y] == str2[y] && f(x, y + 1, str1, str2, str3));
}
bool mixed(const string& str1, const string& str2, const string& str3) {
    int n = str1.size();
    int m = str2.size();
    if (n + m != str3.size()) return false;
    if (n == 0) return str2 == str3;
    if (m == 0) return str1 == str3;
    dp.assign(n, vector<int>(m, -1));
    return f(0, 0, str1, str2, str3);
}



int main() {
    cout << mixed("abc", "abb", "abbabc") << endl;
    cout << mixed("abc", "abb", "ababbc") << endl;
}
