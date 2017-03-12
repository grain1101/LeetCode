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
    // 125. Valid Palindrome
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        bool flag = true;
        while(i < j && flag){
            while(!isalnum(s[i])) i++;
            while (!isalnum(s[j])) j--;
            if (i < j && tolower(s[i++]) != tolower(s[j--])) flag = false;
        }
        return flag;
    }
};


int main() {
    Solution s1;
    string s = "A man, a plan, a canal: Panama";
    auto result = s1.isPalindrome(s);
    cout << result << endl;
}
