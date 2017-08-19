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
    // 60. Permutation Sequence
    string getPermutation(int n, int k) {
        string ans;
        vector<int> p(n+1, 1);
        for(int i = 1; i <= n; i++){
            p[i] = p[i-1] * i;
        }
        vector<int> mark(n, 0);
        k = k - 1;
        for(int i = n - 1; i >=0; i--){
            int index = k / p[i];
            for(int j = 0; j <= index; j++){
                if(mark[j] == 1) index++;
            }
            mark[index] = 1;
            ans.push_back('1' + index);
            k = k % p[i];
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
