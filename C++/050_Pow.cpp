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

class Solution {
  public:
    // 50. Pow(x, n)
    // O(n) = log(n)
    // myPow(0, -1), myPow(2.000, -2147483648)
    double dfs(double x, long long n){
        if (n == 1) return x;
        if (n == 0) return 1;
        double tmp = 1;
        if (n % 2 != 0) {
            tmp = x;
        }
        double half = myPow(x, n/2);
        return half * half * tmp;
    }
    double myPow(double x, int n) {
        if (n < 0 && x == 0) return numeric_limits<double>::infinity();
        double ans = dfs(x, abs(0ll + n));
        return n<0? 1 / ans : ans;
    }
};

int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    auto result = s1.myPow(0,-1);
//    for(auto r : result){
//        for(auto t : r){
//            cout << t;
//        }
//        cout << endl;
//    }
    cout << result << endl;
    return 0;
}
