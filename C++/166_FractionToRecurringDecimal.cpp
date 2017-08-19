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
#include <cassert>
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // 166. Fraction to Recurring Decimal
    // negative number
    // test cases: (1,6) (-2147483648, -1) (20, 51)
    string i2s(long long n){
        ostringstream ss;
        ss << n;
        return ss.str();
    }
    void division(long long numerator, long long denominator){
        if (numerator == 0) return;
        long long  tmp = numerator % denominator;
        if (ans.size() == 0){
            ans += i2s(numerator / denominator);
            ans += tmp ? "." : "";
            //cout << i2s(numerator / denominator) << endl;
            division(tmp * 10, denominator);
        } else {
            if (remainders.find(tmp) == remainders.end()){
                ans += numerator / denominator + '0';
                remainders[tmp] = ans.size();
                division(tmp * 10, denominator);
            }else {
                if ( numerator / denominator +'0' != ans[remainders[tmp] - 1]){
                    ans += i2s(numerator / denominator);
                    ans.insert(remainders[tmp], "(");
                } else {
                    ans.insert(remainders[tmp] - 1, "(");
                }
                ans += ")";
                return;
            }
        }
    }
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string flag;
        if (numerator * 1ll * denominator < 0) flag += "-";
        division(abs(numerator*1ll), abs(denominator*1ll));

        return flag + ans;
    }
private:
    string ans;
    unordered_map<long long, int> remainders;
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,5,4,7};
    string v1 = "0.1";
    string v2 = "1.0.0";
    auto r = s1.fractionToDecimal(1,6);
    cout << r << endl;
}
