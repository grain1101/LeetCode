#include "leetcode.h"
bool isBadVersion(int version){
    return version >= 1 ;
}

class Solution {
public:
    // 316. Remove Duplicate Letters
    string removeDuplicateLetters(string s) {
       vector<int> cnts(256, 0);
       vector<bool> visited(256, false);
       for(auto c : s) cnts[c]++;
       string ret = "0";
       for(char c : s){
            cnts[c]--;
            if (visited[c]) continue;
            while(c < ret.back() && cnts[ret.back()]){
                visited[ret.back()] = false;
                ret.pop_back();
            }
            ret += c;
            visited[c] = true;
       }
       return ret.substr(1);
    }
};


int main() {
    Solution s1;
    vector<int> nums = {0,1};
    string s = "cbacdcbc";
    auto ans = s1.removeDuplicateLetters(s);
    cout << ans << endl;
    //showV(nums);
    //show(ans);
    //showV(ans);
}
