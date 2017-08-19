#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 6. ZigZag Conversion
    // Input: PAYPALISHIRING
    // Output: PAHNAPLSIIGYIR
    // P   A   H   N
    // A P L S I I G
    // Y   I   R
    string convert(string s, int numRows) {
        if(s.size()<=numRows || numRows == 1) return s;
        vector<string> result(numRows, "");
        int j = 0;
        int flag = -1;
        for(int i=0;i<s.size();i++){
            if(j == 0 || j == numRows-1){
                flag *= -1;
            }
            result[j].push_back(s[i]);
            j+=flag;
        }
        string tmp;
        for(int i=0;i<numRows;i++){
            tmp += result[i];
        }
        return tmp;
    }
};

int main()
{
    // 1. Input test cases
    string s = "PAYPALISHIRING";

    // 2. Run
    Solution s1;
    auto result = s1.convert(s,3);
    // 3. Compare output
    cout << result << endl;
    return 0;
}
