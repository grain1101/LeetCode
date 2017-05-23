#include "leetcode.h"

// 402. Remove K Digits
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto n : num){
            while(!st.empty() && n < st.top() && k > 0){
                st.pop();
                k--;
            }
            st.push(n);
        }
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }
        string ret;
        while(!st.empty()){
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        int i = 0;
        while(ret[i] == '0') i++;
        return ret.size() == i ? "0" : ret.substr(i);
    }
};



int main() {
    Solution s1;
    string num = "10200";
    int k = 1;
    auto ans = s1.removeKdigits(num, k);
    cout << ans << endl;
}
