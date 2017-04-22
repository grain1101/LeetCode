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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 struct TreeNode {
    int val;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Solution {
public:
    // 187. Repeated DNA Sequences
    int c2i(char c){
        switch(c){
            case 'A': return 0; // must start from '0', otherwise will run time error
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
    }
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};
        vector<int> seq(1<<20, 0);
        int value = 0;
        for(int i = 0; i < 10; i++){
            value = value * 4 + c2i(s[i]);
        }
        seq[value]++;
        vector<string> ans;
        for(int i = 10; i < s.size(); i++){
            value = value * 4 + c2i(s[i]) - c2i(s[i-10]) * (1 << 20); // 4^10 = 2^20 = 1 << 20;
            seq[value]++;
            if (seq[value] == 2){
                ans.push_back(s.substr(i - 9, 10));
            }
        }
        return ans;
    }
};

int main() {
}
