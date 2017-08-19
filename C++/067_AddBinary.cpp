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
    // 67. Add Binary
    string addBinary(string a, string b) {
        int carry = 0, m = a.size() - 1, n = b.size() - 1;
        string ret = "";
        while(m >= 0 || n >= 0 || carry) {
            int numa = (m>=0 ? a[m] - '0' : 0);
            int numb = (n>=0 ? b[n] - '0' : 0);
            int ans = numa + numb + carry;
            carry = ans / 2;
            ret.push_back(ans % 2 + '0');
            m--; n--;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    string a = "110";
    string b = "10";
    auto result = s1.addBinary(a, b);
    cout << result << endl;
    return 0;
}
