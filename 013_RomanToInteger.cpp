#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 13. Roman to Integer
    // input:[1, 3999]
    // Roman:
    int roman2Int(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }
    int romanToInt(string s) {
        int result = 0;
        int len = s.size();
        if(len==0) return result;
        if(len==1) return roman2Int(s[0]);
        for(int i=0;i<len;i++){
            if(i+1 < len && roman2Int(s[i+1]) > roman2Int(s[i])){
                result += roman2Int(s[i+1]) - roman2Int(s[i]);
                i++;
                continue;
            }
            result += roman2Int(s[i]);
        }
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

    // 2. Run
    Solution s1;
    auto result = s1.romanToInt(s);

    // 3. Compare output

    cout << result << endl;
    return 0;
}
