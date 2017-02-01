#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 17. Letter Combinations of a Phone Number
    // input: "23"
    // output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
    // Phone Number = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
    // DFS
    void dfs(const string& digits, const vector<string>& phone, vector<string>& result, string path, int pointer){
        if(path.size() == digits.size()){
            result.push_back(path);
            return;
        }
        int num = digits[pointer] - '0';
        string s = phone[num];
        for(int i=0;i<s.size();i++){
            path.push_back(s[i]);
            dfs(digits, phone, result, path, pointer+1);
            path.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.size()<1) return {};
        vector<string> result;
        dfs(digits, phone, result, "", 0);
        return result;
    }
};

int main()
{
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {-1, 2, 1, -4};
    string s = "23";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};

    // 2. Run
    Solution s1;
    auto result = s1.letterCombinations(s);

    // 3. Compare output
//    for(auto n : result){
        for(auto num : result){
            cout << num << " ";
        }
        cout << endl;
//    }
//    cout << result << endl;
    return 0;
}
