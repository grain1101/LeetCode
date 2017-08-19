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
    // 55. Jump Game
    bool canJump(vector<int>& nums) {

    }
};


int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    auto result = s1.totalNQueens(8);
//    for(auto r : result){
//        for(auto t : r){
//            cout << t<<endl;
//        }
//        cout << endl;
//    }
    cout << result << endl;
    return 0;
}
