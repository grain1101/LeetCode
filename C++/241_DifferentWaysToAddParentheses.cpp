#include "leetcode.h"
class Solution {
public:
    // 241. Different Ways to Add Parentheses
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for(int i = 0; i < input.size(); i++){
            char cur = input[i];
            if (!isdigit(cur)){
                vector<int> beforPart= diffWaysToCompute(input.substr(0, i));
                vector<int> endPart = diffWaysToCompute(input.substr(i + 1));
                for(auto a : beforPart){
                    for(auto b : endPart){
                        if (cur == '+'){
                            result.push_back(a + b);
                        }
                        if (cur == '-'){
                            result.push_back(a - b);
                        }
                        if (cur == '*'){
                            result.push_back(a * b);
                        }
                    }
                }
            }
        }
        if (result.empty()){
            result.push_back(atoi(input.c_str()));
        }
        return result;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,4};
    string s = "1+1";
    auto ans = s1.diffWaysToCompute(s);
    //cout << ans << endl;
    showV(ans);
    //show(ans);
    //showV(ans);
}
