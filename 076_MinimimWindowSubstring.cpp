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
        int Tcnt[256] = {0};
        for(int i = 0; i < t.size(); i++){
            Tcnt[t[i]]++;
        }
        int need = t.size();
        int Stmp[256] = {0};
        string ans;
        int l = 0;
        for(int i = 0; i < s.size(); i++){
            Stmp[s[i]]++;
            if (Stmp[s[i]] <= Tcnt[s[i]]){ // s[i] is in string t
                need--;
            }
            while(need == 0){
                // update ans
                if (ans.size() == 0 || ans.size() > i - l + 1){
                    ans = s.substr(l, i - l + 1);
                }
                // slide l to remove s[l] in Stmp[s[l]]
                Stmp[s[l]]--;
                if (Stmp[s[l]] < Tcnt[s[l]]) need--;
                l++;
            }
        }
        return ans;
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
