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
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
}

//"0.1   "
//"3"
//"    "
//".  "
//"2e33"
//"2.e333  "
//"  1  2 . 3"
//"1  "
//"6+1"

class Solution {
  public:
    // 65. Valid Number
    // " 005047e+6", "46.e3", "3.", ".1", "12 23", "12seee234", "0.1   "
    bool isNumber(string s) {
        int i = 0;
        if(s.size() == 0) return false;
        // remove pre white spaces & flag + / -
        while(s[i] == ' ') i++;
        if(s[i] == '+' || s[i] == '-') i++;
        // " ", "+"
        if(i == s.size()) return false;
        // "    1.???????"
        int dCount = 0; // digits count
        int pCount = 0; // point count
        for(;i<s.size() && (isdigit(s[i]) || s[i] == '.'); i++){
            s[i] == '.' ? pCount++ : dCount++;
        }
        if(pCount>1 || dCount<1) return false;
        if(i == s.size()) return true;
        if(s[i] == ' '){
            while(i < s.size() && s[i] == ' '){
                i++;
            }
            return (i == s.size());
        }

        // "     1.e+11"
        dCount = 0;
        int eCount = 0; // 'e' count
        for(;i<s.size() && (s[i] == 'e' || isdigit(s[i])); i++){
            s[i] == 'e' ? eCount++ : dCount++;
            if(s[i] == 'e' && i < s.size() && (s[i+1] == '+' || s[i+1] == '-')) i++;
        }
        if(eCount > 1 || dCount < 1) return false;
        // remove white spaces behind
        while(i < s.size()){
            if(s[i] != ' ') return false;
            i++;
        }
        return true;
    }
};


int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    string s = "6e+1";
    auto result = s1.isNumber(s);
    cout << result << endl;
    return 0;
}
