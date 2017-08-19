#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 14. Longest Common Prefix
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if(strs.size()==1) return strs[0];
        for(int i=0;i<strs.size();i++){
            int p=0;
            if(i==0){
                while(p < strs[i].size() && strs[i][p] == strs[i+1][p]){
                    result += strs[i][p];
                    p++;
                }
            }else{
                string tmp;
                while(p<result.size() && strs[i][p] == result[p]){
                    tmp += result[p];
                    p++;
                }
                if(p<result.size()) result = tmp;
            }
        }
        return result;
    }
    string longestCommonPrefix_1(vector<string>& strs) {
        string result;
        if(strs.size()==0) return result;
        if(strs.size()==1) return strs[0];
        sort(strs.begin(), strs.end());
        int p=0;
        while(p<strs[0].size() && strs[0][p]==strs[strs.size()-1][p]){
            p++;
        }
        result = strs[0].substr(0,p);
        return result;
    }
};

int main()
{
    // 1. Input test cases
    int num = 999;
//    vector<int> nums = {3,2,1,3};
    string s = "IV";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};

    // 2. Run
    Solution s1;
    auto result = s1.longestCommonPrefix_1(strs);

    // 3. Compare output

    cout << result << endl;
    return 0;
}
