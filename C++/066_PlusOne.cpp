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
    // 66. Plus One
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1; i >=0; i--){
            carry += digits[i];
            digits[i] = carry % 10;
            carry /= 10;
        }
        if(carry!=0){
            digits.push_back(0);
            for(int i = digits.size()-1; i > 0; i--){
                digits[i] = digits[i-1];
            }
            digits[0] = carry;
        }
        return digits;
    }
};


int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    string s = "6e+1";
    auto result = s1.isNumber(s);
    cout << result << endl;
    return 0;
}
