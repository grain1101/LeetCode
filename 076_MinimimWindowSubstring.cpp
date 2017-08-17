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

class Solution {
  public:
    // 76. Minimum Window Substring
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return "";
        vector<int> m(256, 0);
        for(auto c : t) m[c]++;
        string ret = "";
        int p = 0, cnt = 0;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]--;
            if (m[s[i]] >= 0) cnt++;
            if (cnt == t.size()) {
                while(m[s[p]] + 1 <= 0) {
                    m[s[p]]++;
                    p++;
                }
                if (ret.size() == 0 || ret.size() > i - p + 1) ret = s.substr(p, i - p + 1);
            }
        }
        return ret;
    }
};

int main() {
    //{0,0,1,0,2,0,1,0,1,0,2,1};
    vector<int> nums = {2,0};
    for(auto n : nums){
        cout << n;
    }
    cout << endl;
    Solution s1;
    s1.sortColors(nums);
    for(auto n : nums){
        cout << n;
    }
    cout << endl;
    return 0;
}
