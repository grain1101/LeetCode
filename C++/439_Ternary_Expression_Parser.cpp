#include "leetcode.h"
/**
439_Ternary_Expression_Parser.cpp
"T?T?F:5:3" -> "F"
"F?1:T?4:5" -> "4"
*/


class Solution  {
public:
    string parseTernary(string expression) {
        stack<char> st;
        for(int i = expression.size() - 1; i >= 0; i--){
            if (expression[i] == ':') continue;
            if (expression[i] == '?'){
                char first = st.top(); st.pop();
                char second = st.top(); st.pop();
                if (expression[i - 1] == 'T') st.push(first);
                else st.push(second);
                i--;
                continue;
            }
            st.push(expression[i]);
        }
        return string(1, st.top());
    }
};


int main() {
    Solution s1;
    string test = "T?T?F:5:3";
    cout << s1.parseTernary(test) << endl;
}
