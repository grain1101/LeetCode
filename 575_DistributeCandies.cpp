#include "leetcode.h"
class Solution {
public:
    // 575. Distribute Candies
    int distributeCandies(vector<int>& candies) {
        int n = candies.size();
        unordered_map<int,int> mapping;
        int kinds = 0;
        for(auto c : candies){
            if (mapping.find(c) == mapping.end()) kinds++;
            mapping[c]++;
        }
        if (kinds >= n / 2) return n / 2;
        return kinds;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {0,1,2,4};
    auto ans = s1.minDistance();
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
