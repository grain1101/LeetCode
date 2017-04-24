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

class Solution {
public:
    // 205. Isomorphic Strings
    string numericString(string s){
        unordered_map<char, int> chars;
        int k = 0;
        string sn = "";
        for(int i = 0;i < s.size(); i++){
            if (chars.find(s[i]) == chars.end()){
                chars[s[i]] = k;
                sn += k + '0';
                k++;
            } else {
                sn += chars[s[i]];
            }
        }
        return sn;
    }
    bool isIsomorphic(string s, string t) {
        if (s.size() == 0) return true;
        return numericString(s) == numericString(t);
    }
};

int main() {
    Solution s1;
    string s = "egg";
    string t = "t2a";
    auto ans = s1.isIsomorphic(s, t);
    cout << ans << endl;
}
