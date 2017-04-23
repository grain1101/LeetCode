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

class Solution {
public:
    // 202. Happy Number
    int squareSum(int n){
        int ans = 0, tmp;
        while(n){
            tmp = n % 10;
            ans += tmp * tmp;
            n = n / 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        // if it drop into endless, must has cycle
        set<int> sums;
        while(1){
            if (n == 1) return true;
            int tmp = squareSum(n);
            if (sums.find(tmp) == sums.end()){
                sums.insert(tmp);
                n = tmp;
            } else {
                return false;
            }
        }
    }
    bool isHappy1(int n){
        // Floyd Cycle detection algorithm
        // same as Linked List Cycle
        int slow = n;
        int fast = n;
        while(1){
            if (slow == 1) return true;
            slow = squareSum(slow);
            fast = squareSum(fast);
            fast = squareSum(fast);
            if (fast != 1 && slow == fast) return false;
        }
    }
};

int main() {
    Solution s1;
    auto ans = s1.isHappy1(100);
    cout << ans << endl;
}
