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
    // 59. Spiral Matrix II
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int x1 = 0;
        int y1 = 0;
        int x2 = n - 1;
        int y2 = n - 1;
        int num = 1;
        while(x1 <= x2 && y1 <= y2){
            if(x1 == x2 || y1 == y2){
                if(x1 == x2){
                    for(int i = y1; i <= y2; i++){
                        ans[x1][i] = num++;
                    }
                } else if(y1 == y2){
                    for(int i = x1; i <= x2; i++){
                        ans[i][y1] = num++;
                    }
                }
            } else {
                for(int i = y1; i < y2; i++) ans[x1][i] = num++;
                for(int i = x1; i < x2; i++) ans[i][y2] = num++;
                for(int i = y2; i > y1; i--) ans[x2][i] = num++;
                for(int i = x2; i > x1; i--) ans[i][y1] = num++;
            }
            x1++;
            y1++;
            x2--;
            y2--;
        }
        return ans;
    }
};


int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    auto result = s1.generateMatrix(3);
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
//    cout << result << endl;
    return 0;
}
