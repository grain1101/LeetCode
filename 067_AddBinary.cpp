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
        int m = a.size();
        int n = b.size();
        if(m == 0) return b;
        if(n == 0) return a;
        int p = m - 1;
        int q = n - 1;
        string ans;
        int carry = 0;
        while(p >= 0 || q >= 0 || carry){
            int num_a = p>=0 ? a[p] - '0' : 0;
            int num_b = q>=0 ? b[q] - '0' : 0;
            carry += num_a + num_b;
            ans.push_back(carry%2 + '0');
            carry /= 2;
            p--;
            q--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
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
