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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 43. Multiply Strings
    string i2s(int n){
        ostringstream buffer;
        buffer << n;
        return buffer.str();
    }
    int s2i(string s){
        int n = 0;
        for(int i=0;i<s.size();i++){
            n = n*10 + s[i] - '0';
        }
        return n;
    }
    string add(string a, string b){
        if(b.size() < a.size()) return add(b, a);
        if(a.size()==0) return b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int i=0, j=0;
        while(i<b.size()){
            int num1 = 0, num2 = 0;
            if(i<a.size())
                num1 = a[i] - '0';
            num2 = b[i] - '0';
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            b[i++] = sum%10 + '0';
        }
        if(carry) {
            b.push_back('1');
        }
        reverse(b.begin(), b.end());
        return b;
    }
    string multiply(string a, string b) {
        if (a.size() > b.size()) return multiply(b, a);
        string result;
        int p = 0, q = 0;
        string num;
        for(int i=a.size()-1;i>=0;i--){
            string tmp = "";
            int carry = 0;
            int num1 = a[i] - '0';
            for(int j=b.size()-1;j>=0;j--){
                int num2 = b[j] - '0';
                //cout << "num1: " << num1 << "num2: " << num2 << endl;
                int sum = num1 * num2 + carry;
                carry = sum / 10;
                tmp.append(i2s(sum%10));
            }
            if(carry) tmp.append(i2s(carry));
            reverse(tmp.begin(), tmp.end());
            tmp.append(a.size()-i-1, '0');
            //cout << "tmp: "<< tmp << " result:" << result << endl;
            result = add(tmp, result);
        }
        return result;
    }
};

int main() {
    // 1. Input test cases
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int n = 8;
    string a = "123456789";
    string b = "987654321";
    // 2. Run
    Solution s1;
    auto result = s1.multiply(a,b);

    // 3. Compare output
//    for(auto i : result){
//        for(auto t : i)
//            cout << t << " ";
//        cout << endl;
//    }

    cout << result << endl;
    return 0;
}
