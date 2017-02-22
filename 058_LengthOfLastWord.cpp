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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
}

class Solution {
  public:
    // 58. Length of Last Word
    // Cases: "a"; "a "
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int i;
        bool flag = false;
        for(i = 0; i < s.size(); i++){
            if(s[i] != ' ') break;
        }
        for(i; i < s.size(); i++){
            if(s[i] == ' ') {
                flag = true;
                break;
            }
        }
        return flag ? i : s.size();
    }
};


int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    auto result = s1.merge(intervals);
//    for(auto r : result){
//        for(auto t : r){
//            cout << t<<endl;
//        }
//        cout << endl;
//    }
    cout << result << endl;
    return 0;
}
