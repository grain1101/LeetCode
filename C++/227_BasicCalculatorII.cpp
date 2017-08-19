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
#include<list>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 227. Basic Calculator II
    int calculate(string s) {
        int ret = 0, num = 0;
        char sign = '+';
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if (isdigit(s[i])) num = num * 10 + s[i] - '0';
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1) {
                if (sign == '+'){ // notice: sign is before s[i] operator;
                    st.push(num);
                }
                if (sign == '-'){
                    st.push(-num);
                }
                if (sign == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                }
                if (sign == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                sign = s[i];
                num = 0;
            }
        }
        while(!st.empty()){
            //cout << st.top() << endl;
            ret += st.top();
            st.pop();
        }
        return ret;
    }
};

int main() {
    Solution s1;
    //  3+5 / 2
    string s = " 3+5 / 2 ";
    auto ans = s1.calculate(s);
    cout << ans << endl;
    //show(ans);
    //showV(ans);
}
