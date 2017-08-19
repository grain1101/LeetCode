#include "leetcode.h"

// 591. Tag Validator
class Solution {
public:
    //  "<DIV>This is the first line <![CDATA[<div>]]></DIV>"
    const string cdata_s = "<![CDATA[";
    const string cdata_e = "]]>";
    bool isValid(string code) {
        if (code.size() < 6) return false;
        stack<string> st;
        int n = code.size();
        for(int i = 0; i < n; i++){
            if (code[i] == '<'){
                if (i + 1 >= n) return false;
                if (i > 0 && st.empty()) return false;
                // <DIV>
                if (isupper(code[i + 1])){
                    int j = i + 1;
                    while(j < n && code[j] != '>') {
                        if (!isupper(code[j])) return false;
                        j++;
                    }
                    if (j - i - 1 > 9) return false;
                    st.push(code.substr(i + 1, j - i - 1));
                    i = j;
                }
                // </DIV>
                else if (code[i + 1] == '/'){
                    int j = i + 2;
                    while(j < n && code[j] != '>') {
                        if (!isupper(code[j])) return false;
                        j++;
                    }
                    if (j - i - 2 > 9) return false;
                    if (st.empty() || st.top() != code.substr(i + 2, j - i - 2)) return false;
                    st.pop();
                    i = j;
                }
                // <![CDATA[<div>]]>
                else if (code[i + 1] == '!'){
                    if (code.find(cdata_s, i) != i) return false;
                    int idx = code.find(cdata_e, i + cdata_s.size());
                    if (idx == string::npos) return false;
                    if (st.empty()) return false;
                    i = idx + cdata_e.size() - 1;
                }else {
                    return false;
                }
            }
            else{
                if (st.empty()) return false;
                continue;
            }
        }
        return st.size() == 0;
    }
};

int main() {
    Solution s1;
    string code = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
    auto ans = s1.isValid(code);
    cout << ans << endl;
}
