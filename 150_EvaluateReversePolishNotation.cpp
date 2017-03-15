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
#include <set>
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
        cout << r;
    cout << endl;
}


class Solution {
public:
    // 150. Evaluate Reverse Polish Notation
    // ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
    // ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
    int s2i(const string& s){
        istringstream iss(s);
        int ans = 0;
        iss >> ans;
        return ans;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/" )
                st.push(s2i(tokens[i]));
            else{
                if (st.size() >= 2){
                    int second = st.top();
                    st.pop();
                    int first = st.top();
                    st.pop();
                    int tmp = 0;
                    if (tokens[i] == "+") tmp = first + second;
                    if (tokens[i] == "-") tmp = first - second;
                    if (tokens[i] == "*") tmp = first * second;
                    if (tokens[i] == "/") tmp = first / second;
                    st.push(tmp);
                }
            }
        }
        return st.top();
    }
};

int main() {
    Solution s1;
    string s = "   a     ";
    s1.reverseWords(s);
    cout << s << endl;
}
