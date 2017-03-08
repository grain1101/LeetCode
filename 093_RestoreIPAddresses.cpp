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

class Solution {
public:
    // 93. Restore IP Addresses
    // "25525511135"
    // ["255.255.11.135", "255.255.111.35"]
    void dfs(const string& s, vector<string>& ans, vector<string>& path, int level){
        if (path.size() == 3){
            string last = s.substr(level);
            if (last.size() >=1 && last.size() <= 3 && atoi(last.c_str()) < 256){
                if (last.size() > 1 && last[0] == '0') return;
                ans.push_back(path[0] + '.' + path[1] + '.' + path[2] + '.' + last);
                return;
            }
        }
        int tmp = 0;
        for(int i = level; i < s.size(); i++){
            tmp = tmp * 10 + s[i] - '0';
            // IP addresses restrictions !"012" !"256"
            if (i > level && s[level] == '0' || tmp > 256 ) return;
            path.push_back(s.substr(level, i - level + 1));
            dfs(s, ans, path, i + 1);
            path.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 16) return {};
        vector<string> ans;
        vector<string> path;
        dfs(s, ans, path, 0);
        return ans;
    }
};




int main() {
    string s = "25525511135";
    Solution s1;
    auto result =  s1.restoreIpAddresses(s);
    for(auto r : result)
        cout << r << endl;
    cout << endl;
    //cout << result << endl;
}
