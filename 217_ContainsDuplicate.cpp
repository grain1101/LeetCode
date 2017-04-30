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
    // 217. Contains Duplicate
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mapping;
        for(auto n : nums){
            mapping[n]++;
            if (mapping[n] > 1) return true;
        }
        return false;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {0,1,0,-1};
    int k = 0;
    auto ans = s1.containsDuplicate(nums);
    cout << ans << endl;
    //show(ans);
    //showV(ans);
}
