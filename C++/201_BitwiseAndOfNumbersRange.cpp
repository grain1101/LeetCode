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
    // 201. Bitwise AND of Numbers Range
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) return m;
        int num = 0;
        for(int i = 0; i < 32; i++){
            if (((m >> i)&1) ^ ((n >> i) & 1)) num = i + 1;
        }
        return (n >> num) << num;
    }

    int rangeBitwiseAnd2(int m, int n) {
        return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
    }

    int rangeBitwiseAnd3(int m, int n) {
        while(m < n) n = n & (n - 1);
        return n;
    }
};

int main() {
    Solution s1;
    auto ans = s1.rangeBitwiseAnd(9,10);
    cout << ans << endl;
}
