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
    // 131. Palindrome Partitioning
    bool isPalindrome(string a){
        if (a.size() < 2) return true;
        for(int i = 0; i < a.size(); i++){
            if (a[i] != a[a.size() - 1 - i]) return false;
        }
        return true;
    }
    void dfs(const string& s, int k, vector<string>& path){
        if (k == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = k; i < s.size(); i++){
            string tmp = s.substr(k, i - k +1);
            if (isPalindrome(tmp)){
                path.push_back(tmp);
                dfs(s, i + 1, path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ans.clear();
        vector<string> path;
        dfs(s, 0, path);
        return ans;
    }
private:
    vector<vector<string>> ans;
};

int main() {
    Solution s1;
    string s = "";
    auto result = s1.partition(s);
    show(result);
}
