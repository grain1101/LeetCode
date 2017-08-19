#include "leetcode.h"

// 553. Optimal Division
class Solution {
public:
//    Input: [1000,100,10,2]; [2]; [2,3]
//    Output: "1000/(100/10/2)"; "2"; "2/3";
    string optimalDivision(vector<int>& nums) {
        string ret = to_string(nums[0]);
        if (nums.size() == 1) return ret;
        if (nums.size() == 2) return ret + "/" + to_string(nums[1]);
        ret += "/(";
        for(int i = 1; i < nums.size(); i++){
            ret += to_string(nums[i]);
            if (i != nums.size() - 1){
                ret += "/";
            }
        }
        ret += ")";
        return ret;
    }
};


int main() {
    Solution2 s1;
    string s = "abab";
    auto ans = s1.repeatedSubstringPattern("abadabad");
    cout << ans << endl;

    int i = 0, j = 0;
}
