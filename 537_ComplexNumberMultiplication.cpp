#include "leetcode.h"

// 537. Complex Number Multiplication
class ComplexNumber{
public:
    ComplexNumber(const string& s){
        parse(s);
    }
    ComplexNumber operator*(const ComplexNumber& rhs) {
        int nx = x * rhs.x - y * rhs.y;
        int ny = x * rhs.y + y * rhs.x;
        x = nx;
        y = ny;
        return *this;
    }
    string to_str(){
        return to_string(x) + "+" + to_string(y) + "i";
    }
private:
    int x;
    int y;
    // 1+-1i,  -1+-1i; 1+1i;
    void parse(const string& s){
        int idx = 0;
        x = parseInt(s, idx);
        y = parseInt(s, idx);
    }
    int parseInt(const string& s, int& idx){
        int flag = 1;
        if (s[idx] == '-'){
            flag = -1;
            idx++;
        }
        int ret = 0;
        while(isdigit(s[idx])) {
            ret = ret * 10 + s[idx] - '0';
            idx++;
        }
        idx++;
        return flag * ret;
    }
};

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        ComplexNumber c1(a);
        ComplexNumber c2(b);
        c1 * c2;
        return c1.to_str();
    }
};


int main() {
    Solution2 s1;
    string s = "abab";
    auto ans = s1.repeatedSubstringPattern("abadabad");
    cout << ans << endl;

    int i = 0, j = 0;
}
