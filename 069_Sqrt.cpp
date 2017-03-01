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
    // 69. Sqrt(x)
    // binary search
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x < 0) return INT_MIN;
        long long l = 1;
        long long r = x;
        while(l + 1 < r) {
            long long mid = l*1LL + (r - l) / 2;
            long long tmp = mid * mid;
            if (tmp == x) return mid;
            if (tmp < x) l = mid;
            if (tmp > x) r = mid;
        }
        return l;
    }
};


int main() {
    vector<int> nums = {0,1,2,2,2,3,3,3,3,4};
    Solution s1;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int x = 81;
    auto result = s1.mySqrt(x);
//    binary_search();
    cout << result << endl;
    return 0;
}
