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
#include<list>
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

class Solution {
public:
    // 214. Shortest Palindrome
    string shortestPalindrome(string s) {
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        string l = s + "#" + tmp;
        // catacb -> catacb#bcatac
        failure.assign(l.size() , -1);
        for(int i = 1, j = failure[0]; i < l.size(); i++){
            while(j >=0 && l[j + 1] != l[i]){
                j = failure[j];
            }
            if (l[j + 1] == l[i]) j++;
            failure[i] = j;
        }
        showV(failure);
        return tmp.substr(0, s.size() - failure[l.size() - 1] - 1) + s;
    }
    void prefix(string &s){
        failure.assign(s.size(), -1);
        int j = failure[0];
        for(int i = 1; i < s.size(); i++){
            while(j >= 0 && s[j + 1] != s[i]){
                j = failure[j];
            }
            if (s[j + 1] == s[i]) j++;
            failure[i] = j;
        }
    }
    void Morris_Pratt(string &t, string &p){
        if (p.size() > t.size()) return;
        failure.assign(t.size(), -1);
        for(int i = 0, j = -1; i < p.size(); i++){
            while(j >= 0 && p[j + 1] != p[i]){
                j = failure[j];
            }
            if (p[j + 1] == p[i]) j++;
            failure[i] = j;
        }
        for(int i = 0, j = -1; i < t.size(); i++){
            while(j >= 0 && p[j + 1] != t[i]){
                j = failure[j];
            }
            if (p[j + 1] == t[i]) j++;
            if (j == p.size() - 1){
                cout << i - p.size() + 1 << endl;
                j = failure[j];
            }
        }
    }
private:
    vector<int> failure;
};



int main() {
    Solution s1;
    vector<int> nums = {};
    string s = "aaab";
    auto ans = s1.shortestPalindrome(s);
    showV(ans);
}
