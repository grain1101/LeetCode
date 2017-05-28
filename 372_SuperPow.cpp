#include "leetcode.h"

// 372. Super Pow
class Solution {
public:
    const static int mod;
    int superPow(int a, vector<int>& b) {
        removeLeadingZeros(b);
        if (b.size() == 0) return 1;
        int carry = dividedBy2(b);
        int half = superPow(a, b);
        return half * half % mod *1LL* (carry ? a : 1) % mod;
    }
private:
    void removeLeadingZeros(vector<int>& b){
        vector<int> newb;
        bool allZero = true;
        for(auto n : b){
            if (n != 0) allZero = false;
            if (!allZero) newb.push_back(n);
        }
        b = newb;
    }
    int dividedBy2(vector<int>& b){
        int carry = 0;
        for(auto& n : b){
            int tmp = carry * 10 + n;
            carry = tmp % 2;
            n = tmp / 2;
        }
        return carry;
    }
};
const int Solution::mod = 1337;

int main() {
    Solution s1;
    auto ans = s1.superPow()
    //showV(ans);
    cout << ans << endl;
}
