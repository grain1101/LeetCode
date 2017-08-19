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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 38. Count and Say
    // int to string: #include <sstream>
    // ostringstream
    string i2s(int n){
        ostringstream buffer;
        buffer << n;
        return buffer.str();
    }
    string countAndSay(int n) {
        if (n < 2) return "1";
        string s = "1";
        for(int i=1;i<n;i++){
            int cnt = 1;
            string tmp = "";
            int j;
            for(j=0;j<s.size();j++){
                if (j<s.size()-1 && s[j]==s[j+1]) cnt++;
                else {
                    tmp += i2s(cnt) + s[j];
                    cnt = 1;
                }
            }
            if(j==s.size() && cnt!=1){
                tmp += i2s(cnt) + s[j-1];
                cnt = 1;
            }
            s = tmp;
        }
        return s;
    }
};

void show(vector<vector<char>> sudoku){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << sudoku[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {1,3,5,6};
    string ss = "))))()";
    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(0);
    ListNode *p = head;
    int n = 4;
    // 2. Run
    Solution s1;
    auto result = s1.countAndSay(n);

    // 3. Compare output
//    for(auto i : result){
//        cout << i << " ";
//    }
//    cout << endl;
    cout << result << endl;
    return 0;
}
