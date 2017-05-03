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
#include<list>
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
    // 228. Summary Ranges
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.size() == 0) return ret;
        for(int i = 0; i < nums.size(); i++){
            string s = "";
            s += i2s(nums[i]);
            int j = i + 1;
            while(j < nums.size() && nums[j] - 1 == nums[j - 1]) j++;
            if (j != i + 1) {
               s += "->";
               s += i2s(nums[j - 1]);
            }
            ret.push_back(s);
            i = j - 1;
        }
        return ret;
    }
    string i2s(int i){
        stringstream ss;
        ss << i;
        return ss.str();
    }
};

int main() {
    Solution s1;
    vector<int> nums = {-1};
    auto ans = s1.summaryRanges(nums);
    showV(ans);
    //show(ans);
    //showV(ans);
}
