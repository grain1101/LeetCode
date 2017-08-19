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
#include<list>
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
    // 224. Basic Calculator
    int calculate(string s) {
        if (s.size() == 0) return 0;
        stack<int> nums, ops;
        int num = 0, ret = 0, sign = 1;
        for(auto c : s){
            if (isdigit(c)) num = num * 10 + c -'0';
            else{
                ret += num * sign;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '('){
                    nums.push(ret);
                    ops.push(sign);
                    ret = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()){
                    ret = ops.top() * ret + nums.top();
                    ops.pop();nums.pop();
                }
            }
        }
        ret += sign * num;
        return ret;
    }
};

int main() {
    Solution s1;
    string s = "(1+(4-5+2)-3)+(6+8)";
    auto ans = s1.calculate(s);
    cout << ans << endl;
    //show(ans);
    //showV(ans);
}
