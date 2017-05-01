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
    // 219. Contains Duplicate II
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0 || nums.size() < 2) return false;
        set<int> container;
        for(int i = 0; i < nums.size(); i++){
            if (i > k) container.erase(nums[i-k-1]);
            if (container.find(nums[i]) != container.end()) return true;
            container.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {0,1,0,-1};
    auto ans = s1.containsNearbyDuplicate(nums,3);
    cout << ans << endl;
    //show(ans);
    //showV(ans);
}
